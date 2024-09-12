#ifndef SERIAL_H
#define SERIAL_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>

#include <memory>

typedef enum {
    SWITCH_SONG         = 0x02, // [切歌:02]
    PLAY_STOP           = 0x03, // [播放/暂停:03]
    REPLAY              = 0x0b, // [重唱:0b]
    ORIGINAL_VOCALIST   = 0x0c, // [原伴唱:0c]
}ProtocolCmd;

class Serial : public QObject
{
    Q_OBJECT
public:
    explicit Serial(QObject *parent = nullptr);

private:
    bool set_baud_rate(uint32_t baudRate);
    bool set_parity(int parity);
    bool set_data_bits(int dataBites);
    bool set_stop_bits(int stopBits);
    bool set_flow_control(int flowControl);

    bool parse_protocol(QByteArray &data);

public slots:
    void openSerialPort(QString &deviceName);
    void closeSerialPort();

    void writeData(const QByteArray &data);
    void readData();

    void handleError(QSerialPort::SerialPortError error);

signals:
    void protocol_cmd(ProtocolCmd cmd);

private:
    std::shared_ptr<QSerialPort> serialPort;
};

#endif // SERIAL_H
