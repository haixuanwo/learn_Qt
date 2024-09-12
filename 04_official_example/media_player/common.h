/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2022-07-25 10:00:24
 * @LastEditors: Clark
 * @LastEditTime: 2022-08-08 12:49:02
 * @Description: file content
 */
#ifndef COMMON_H
#define COMMON_H

#include <QObject>
#include <QDebug>
#include <QStringList>
#include <QMessageBox>
#include <QByteArray>
#include <QString>

#include <memory>

#include <string.h>

using std::shared_ptr;
using std::make_shared;

#define PALM_VEIN_WIDTH 480
#define PALM_VEIN_HEIGHT 640

#define WIDTH 360
#define HEIGHT 640

#define DOUBLE_IR_WIDTH 640
#define DOUBLE_IR_HEIGHT 720

/**
 * 模组类型
 */
typedef enum{
    MODULE_DOUBLE_SENSOR,
    MODULE_TRIPLE_SENSOR
}ModuleType;

/**
 * 摄像头状态
 */
typedef enum{
    STATUS_OK,
    STATUS_ERROR
}CameraStatus;

/**
 * @brief 设置数值到2字节空间
 * @param value 数值
 * @param buf 设置的地址
 */
void set_value_to_2Byte_buf(unsigned short value, unsigned char *buf);

/**
 * @brief 获取2字节空间中的数值
 * @param  buf 获取的地址
 * @param  value 获取的数值
 */
void get_value_from_2Byte_buf(unsigned char *buf, unsigned short *value);

/**
 * @brief 设置数值到4字节空间
 * @param value 数值
 * @param buf 设置的地址
 */
void set_value_to_4Byte_buf(unsigned int value, unsigned char *buf);

/**
 * @brief 获取4字节空间中的数值
 * @param  buf 获取的地址
 * @param  value 获取的数值
 */
void get_value_from_4Byte_buf(unsigned char *buf, unsigned int *value);

/**
 * @brief 以十六进制显示数据
 * @param info  数据相关信息
 * @param data  需显示的数据
 */
void show_data_as_hex(const QString &info, QByteArray &data);

/**
 * @brief 以十六进制打印
 * @param data	数据
 * @param dataLen 数据长度
 */
bool print_data_in_hex(const char *str, unsigned char *data, int dataLen);

#endif // COMMON_H
