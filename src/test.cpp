#include <iostream>
#include <ctime>
#include <string>
#include "time_format.hpp"

int main() {

    std::string time_now = timeFormatted(std::chrono::system_clock::now());
    std::cout << time_now << std::endl;



    return 0;
}