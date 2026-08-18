cmake_minimum_required(VERSION 3.16)
project(fridge_door_sensor CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GPIODCXX REQUIRED IMPORTED_TARGET libgpiodcxx)

add_executable(fridge_door_sensor src/main.cpp)
target_link_libraries(fridge_door_sensor PRIVATE PkgConfig::GPIODCXX)

add_executable(time_format_test src/test.cpp src/time_format.cpp)