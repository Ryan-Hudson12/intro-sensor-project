#include <chrono>
#include <gpiod.hpp>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <ctime>
#include <string>


namespace {

constexpr auto kChipPath = "/dev/gpiochip0";
const ::gpiod::line::offset kDoorLineOffset = 17;
constexpr auto kDebouncePeriod = std::chrono::milliseconds(75);

} // namespace

int main()
{
    auto line_settings = ::gpiod::line_settings()
                              .set_direction(::gpiod::line::direction::INPUT)
                              .set_edge_detection(::gpiod::line::edge::RISING)
                              .set_bias(::gpiod::line::bias::PULL_UP)
                              .set_debounce_period(kDebouncePeriod);

    auto request = ::gpiod::chip(kChipPath)
                        .prepare_request()
                        .set_consumer("fridge-door-sensor")
                        .add_line_settings(kDoorLineOffset, line_settings)
                        .do_request();

    ::gpiod::edge_event_buffer buffer;

    for (;;) {
        request.wait_edge_events(std::chrono::nanoseconds(-1));
        request.read_edge_events(buffer);

        for (const auto& event : buffer) {
            if (event.type() == ::gpiod::edge_event::event_type::RISING_EDGE) {
                auto opened_at = std::chrono::system_clock::now();
                // TODO: hand opened_at off to the logger/emailer once those exist.
                (void)opened_at;
                std::cout << "Door opened.\n";
            }
        }
    }

    return 0;
}