#include <string>
#include <ctime>
#include "time_format.hpp"
#include <sstream>
#include <iomanip>


std::string timeFormatted(std::chrono::system_clock::time_point opened_at) {

    std::time_t now_c = std::chrono::system_clock::to_time_t(opened_at);
    std::tm local_tm = *std::localtime(&now_c);
    std::ostringstream date_stream;
    date_stream << std::put_time(&local_tm, "%m-%d-%Y"); // "08-18-2026"
    std::ostringstream  time_stream;
    time_stream << std::put_time(&local_tm, "%I:%M:%S %p"); // "01:52:06 PM"

    return date_stream.str() + " " + time_stream.str();
}