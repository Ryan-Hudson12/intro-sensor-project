# Dev Log

## 2026-08-11 — GPIO edge-watch design and initial implementation

- Reed switch wiring decided: normally-open switch, one leg to the GPIO pin, other to GND, with the GPIO line configured for internal pull-up bias. Door closed (magnet present) reads LOW; door open reads HIGH — so "door opened" is a rising edge. Chosen because it needs no external resistor and is the simplest wiring to reason about.
- Sensor pin chosen: GPIO17 (chip `gpiochip0`, line offset 17, physical pin 11), picked before wiring so the hardware could be matched to the code. Confirmed via `gpiodetect`/`gpioinfo` that `gpiochip0`'s line offsets map 1:1 to BCM GPIO numbers on this board, and that lines 0-1 (`ID_SDA`/`ID_SCL`, reserved for HAT EEPROM) should be avoided.
- Debounce handled via libgpiod v2's built-in `set_debounce_period()` (75ms) rather than hand-rolled timestamp logic — the kernel driver filters switch chatter at the source before an event is ever generated.
- First version of the GPIO watch loop implemented in `src/main.cpp`: opens `gpiochip0`, requests line 17 with the settings above, and blocks on `wait_edge_events()` / `read_edge_events()` — genuinely event-driven, no polling loop.
- Commit: `5743030` "created the initial loop for checking the pin"

## 2026-08-13 — Fixed build error, confirmed detection works on real hardware

- Build failed: `constexpr ::gpiod::line::offset` doesn't compile because `line::offset` isn't a C++ "literal type" (no `constexpr` constructor). Switched to `const`, which only requires immutability, not compile-time evaluability.
- Wired the reed switch to GPIO17 and ran the compiled program over SSH: pulling the magnet away correctly logged "Door opened." — confirms the full chain (wiring, pull-up bias, kernel debounce, rising-edge detection, blocking event loop) works end to end on real hardware.
- Commit: `13af818` "Fix line offset build error and confirm hardware detection works"