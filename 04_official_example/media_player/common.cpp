/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2022-07-25 10:00:24
 * @LastEditors: Clark
 * @LastEditTime: 2022-08-08 12:48:56
 * @Description: file content
 */
#include "common.h"

#define ENABLE_PRINT_HEX_DATA

/**
 * @brief 设置数值到2字节空间
 * @param value 数值
 * @param buf 设置的地址
 */
void set_value_to_2Byte_buf(unsigned short value, unsigned char *buf)
{
    buf[1] = value&0xFF;
    buf[0] = value>>8 & 0xFF;
}

/**
 * @brief 获取2字节空间中的数值
 * @param  buf 获取的地址
 * @param  value 获取的数值
 */
void get_value_from_2Byte_buf(unsigned char *buf, unsigned short *value)
{
    *value  = buf[0]*0x100 + buf[1];
}

/**
 * @brief 设置数值到4字节空间
 * @param value 数值
 * @param buf 设置的地址
 */
void set_value_to_4Byte_buf(unsigned int value, unsigned char *buf)
{
    buf[3] = value & 0xFF;
    buf[2] = value>>8  & 0xFF;
    buf[1] = value>>16 & 0xFF;
    buf[0] = value>>24 & 0xFF;
}

/**
 * @brief 获取4字节空间中的数值
 * @param  buf 获取的地址
 * @param  value 获取的数值
 */
void get_value_from_4Byte_buf(unsigned char *buf, unsigned int *value)
{
    *value = buf[0]<<24;
    *value  += buf[1]<<16;
    *value  += buf[2]<<8;
    *value  += buf[3];
}

/**
 * @brief 以十六进制显示数据
 * @param info  数据相关信息
 * @param data  需显示的数据
 */
void show_data_as_hex(const QString &info, QByteArray &data)
{
#ifdef ENABLE_PRINT_HEX_DATA
    QString showData;
    for(int i = 0; i < data.size(); i++)
    {
        showData += QString("%1 ").arg(data.at(i)&0xFF, 2, 16, QLatin1Char('0'));
    }

    QString strData = info;
    strData += showData;
    qDebug()<<strData;
#endif
}

/**
 * @brief 以十六进制打印
 * @param data	数据
 * @param dataLen 数据长度
 */
bool print_data_in_hex(const char *str, unsigned char *data, int dataLen)
{
#ifdef ENABLE_PRINT_HEX_DATA

#define MAX_SIZE 1024
    if (nullptr == data || dataLen <= 0)
        return false;

    if (dataLen > MAX_SIZE)     // 最多打印1024字节
        dataLen = MAX_SIZE;

    char buf[MAX_SIZE*3 + 1] ={0};   // 一个十六进制用两个字节，加一个空格共3字节

    for(int i = 0; i < dataLen; i++)
    {
        snprintf(buf + i*3, 4, "%02x ", data[i]);   // snprintf会在数据后加'\0'，所以存4字节
    }

    printf("%s:len[%d]:%s\n", str, dataLen, buf);
#endif
    return true;
}
