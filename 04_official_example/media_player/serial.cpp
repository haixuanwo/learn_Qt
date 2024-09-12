#include "serial.h"
#include "common.h"
#include <QDebug>
#include <QMessageBox>

Serial::Serial(QObject *parent)
    : QObject{parent}
{
    serialPort = std::make_shared<QSerialPort>(this);
    connect(serialPort.get(), &QSerialPort::errorOccurred, this, &Serial::handleError);
    connect(serialPort.get(), &QSerialPort::readyRead, this, &Serial::readData);
}

void Serial::openSerialPort(QString &deviceName)
{
    closeSerialPort();

    set_baud_rate(115200);      // 波特率115200
    set_parity(2);              // 无奇偶校验
    set_data_bits(8);           // 8数据位
    set_stop_bits(1);           // 1停止位
    set_flow_control(2);        // 无流控制

    serialPort->setPortName(deviceName);
    bool result = serialPort->open(QIODevice::ReadWrite);
    qDebug() << "open serial:" << deviceName << (result?" success":"fail");
}

void Serial::closeSerialPort()
{
    if (serialPort->isOpen())
    {
        serialPort->close();
    }
}

void Serial::writeData(const QByteArray &data)
{
    serialPort->write(data);
}

void Serial::readData()
{
    QByteArray data = serialPort->readAll();
    show_data_as_hex("read data:", data);
    // writeData(data);
    parse_protocol(data);
}

void Serial::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError)
    {
        // QMessageBox::critical(this, tr("Critical Error"), serialPort->errorString());
        closeSerialPort();
    }
    qDebug() << "handleError";
}

bool Serial::parse_protocol(QByteArray &data)
{
    /*
    [原伴唱:0c]
    [重唱:0b]
    [播放/暂停:03]
    [切歌:02]
    */
    if (0x0c == data[0]
        || 0x0b == data[0]
        || 0x03 == data[0]
        || 0x02 == data[0])
    {
        ProtocolCmd cmd = static_cast<ProtocolCmd>((int)data[0]);
        emit protocol_cmd(cmd);
        qDebug() << "emit protocol_cmd: " << cmd;
    }
    else
    {
        qDebug() << "It's not a protocol cmd";
    }

    return true;
}

//设置波特率
bool Serial::set_baud_rate(uint32_t baudRate)
{
    switch(baudRate)
    {
    case 1200:
    {
        return serialPort->setBaudRate(QSerialPort::Baud1200);
    }
    case 2400:
    {
        return serialPort->setBaudRate(QSerialPort::Baud2400);
    }
    case 9600:
    {
        return serialPort->setBaudRate(QSerialPort::Baud9600);
    }
    case 38400:
    {
        return serialPort->setBaudRate(QSerialPort::Baud38400);
    }
    case 115200:
    {
        return serialPort->setBaudRate(QSerialPort::Baud115200);
    }
    default:
    {
        return false;
    }
    }
}

//设置奇偶校验
bool Serial::set_parity(int parity)
{
    switch(parity)
    {
    case 0:
    {
        return serialPort->setParity(QSerialPort::OddParity);
    }
    case 1:
    {
        return serialPort->setParity(QSerialPort::EvenParity);
    }
    case 2:
    {
        return serialPort->setParity(QSerialPort::NoParity);
    }
    default:
    {
        return false;
    }
    }
}

//设置数据位
bool Serial::set_data_bits(int dataBites)
{
    switch(dataBites)
    {
    case 5:
    {
        return serialPort->setDataBits(QSerialPort::Data5);
    }
    case 6:
    {
        return serialPort->setDataBits(QSerialPort::Data6);
    }
    case 7:
    {
        return serialPort->setDataBits(QSerialPort::Data7);
    }
    case 8:
    {
        return serialPort->setDataBits(QSerialPort::Data8);
    }
    default:
    {
        return false;
    }
    }
}

//设置停止位
bool Serial::set_stop_bits(int stopBits)
{
    switch(stopBits)
    {
    case 1:
    {
        return serialPort->setStopBits(QSerialPort::OneStop);
    }
    case 2:
    {
        return serialPort->setStopBits(QSerialPort::TwoStop);
    }
    default:
    {
        return false;
    }
    }
}

//设置流控制
bool Serial::set_flow_control(int flowControl)
{
    switch(flowControl)
    {
        case 0:
        {
            return serialPort->setFlowControl(QSerialPort::HardwareControl);
        }
        case 1:
        {
            return serialPort->setFlowControl(QSerialPort::SoftwareControl);
        }
        case 2:
        {
            return serialPort->setFlowControl(QSerialPort::NoFlowControl);
        }
        default:
        {
            return false;
        }
    }
}
