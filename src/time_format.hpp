#ifndef TIME_FORMAT_H
#define TIME_FORMAT_H

#include <string>
#include <chrono>

std::string timeFormatted(std::chrono::system_clock::time_point opened_at);

#endif