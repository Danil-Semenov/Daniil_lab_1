#pragma once

#include <chrono>
#include <iostream>
#include <string>

class LogDuration {
public:
    // ������� ��� ���� std::chrono::steady_clock
    // � ������� using ��� ��������
    using Clock = std::chrono::steady_clock;

    LogDuration() {
    }

    LogDuration(const std::string name_of_function)
        :func_name(name_of_function)
    {}

    ~LogDuration() {
        using namespace std::chrono;
        using namespace std::literals;

        const auto end_time = Clock::now();
        const auto dur = end_time - start_time_;
        std::cerr << func_name << ": "s << duration_cast<milliseconds>(dur).count() << " ��"s << std::endl;
    }

private:
    const Clock::time_point start_time_ = Clock::now();
    std::string func_name;
};