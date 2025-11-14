#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "ulp_lp_core.h"
#include "esp_err.h"

// Define the built-in RGB LED pin and number of LEDs
#define LED_PIN 8
#define NUM_LEDS 1

Adafruit_NeoPixel rgbLed(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

// Define some colors
struct RGB {
    uint8_t r, g, b;
};

constexpr RGB COLOR_RED = {255, 0, 0};
constexpr RGB COLOR_GREEN = {0, 255, 0};
constexpr RGB COLOR_BLUE = {0, 0, 255};
constexpr RGB COLOR_OFF = {0, 0, 0};

extern const uint8_t bin_start[] asm("_binary_ulp_main_bin_start"); //refering to app name ulp_main defined in CMakelists.txt
extern const uint8_t bin_end[]   asm("_binary_ulp_main_bin_end"); //refering to app name ulp_main defined in CMakelists.txt

void start_ulp_program() {
    // Change: Load the ULP binary into RTC memory
    ESP_ERROR_CHECK(ulp_lp_core_load_binary(bin_start, (bin_end - bin_start)));

    // Change: Configure the ULP LP core wake-up source and timer
    ulp_lp_core_cfg_t cfg = {
        .wakeup_source = ULP_LP_CORE_WAKEUP_SOURCE_LP_TIMER, // Wake up using LP timer
        .lp_timer_sleep_duration_us = 1000000,              // 1-second sleep duration
    };

    // Change: Start the ULP LP core program
    ESP_ERROR_CHECK(ulp_lp_core_run(&cfg));
}

void setColor(const RGB& color) {
    rgbLed.setPixelColor(0, rgbLed.Color(color.r, color.g, color.b));
    rgbLed.show();
}

void setup() {
    Serial.begin(115200);
    Serial.println("Starting ULP Program...");
    start_ulp_program();
    Serial.println("Starting RGB LED blinking...");
    rgbLed.begin(); // Initialize the NeoPixel library
    rgbLed.show();  // Turn off all LEDs initially
}

void loop() {
    Serial.println("Setting color to RED");
    setColor(COLOR_RED);
    delay(1000);

    Serial.println("Setting color to GREEN");
    setColor(COLOR_GREEN);
    delay(1000);

    Serial.println("Setting color to BLUE");
    setColor(COLOR_BLUE);
    delay(1000);

    Serial.println("Turning off LED");
    setColor(COLOR_OFF);
    delay(1000);
}