/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2022-07-25 10:00:24
 * @LastEditors: Clark
 * @LastEditTime: 2022-08-08 12:48:48
 * @Description: file content
 */
#ifndef CHRONO_TIME_H
#define CHRONO_TIME_H

#include <chrono>
#include <thread>
#include <iostream>

using namespace std::chrono;
using TimePoint = std::chrono::time_point<std::chrono::steady_clock>;

/**
 * @brief C++标准库时间对象
 */
class ChronoTimer
{
public:
    ChronoTimer()
    {
        timeout = 0;
        last = get_now_time();
    }

    TimePoint get_now_time()
    {
        return steady_clock::now();
    }

    TimePoint start()
    {
        last = get_now_time();
        return last;
    }

    unsigned long stop()
    {
        auto now = get_now_time();
        return duration_cast<microseconds>(now - last).count()/1000;  // 返回毫秒数
    }

    void set_timeout(uint64_t timeout)
    {
        this->timeout = timeout;
        last = get_now_time();
    }

    bool is_timeout()
    {
        auto now = get_now_time();
        uint64_t diffTime = duration_cast<microseconds>(now - last).count()/1000;  // 返回毫秒数
        return (diffTime >= timeout);
    }

private:
    TimePoint last;
    uint64_t timeout;
};

#endif // CHRONO_TIME_H
