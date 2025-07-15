[![Build_special_firmware](https://raw.githubusercontent.com/vshymanskyy/StandWithUkraine/main/banner-direct.svg)](https://github.com/vshymanskyy/StandWithUkraine/blob/main/docs/README.md)


# Tasmota Espressif 32: development platform for [PlatformIO](http://platformio.org)

[![Examples](https://github.com/Jason2866/platform-espressif32/actions/workflows/examples.yml/badge.svg)](https://github.com/Jason2866/platform-espressif32/actions/workflows/examples.yml)[![GitHub Releases](https://img.shields.io/github/downloads/tasmota/platform-espressif32/total?label=downloads)](https://github.com/tasmota/platform-espressif32/releases/latest)

Espressif Systems is a privately held, fabless semiconductor company renowned for delivering cost-effective wireless communication microcontrollers. Their innovative solutions are widely adopted in mobile devices and Internet of Things (IoT) applications around the globe.

# Usage

1. [Install PlatformIO](http://platformio.org)
2. Create PlatformIO project and configure a platform option in [platformio.ini](http://docs.platformio.org/page/projectconf.html) file:

## Tasmota release Arduino 3.1.3.250712 and IDF 5.3.3.250702
Support for the ESP32/ESP32solo1, ESP32C2, ESP32C3, ESP32C6, ESP32S2, ESP32S3 and ESP32-H2
```
[platformio]
platform = https://github.com/tasmota/platform-espressif32/releases/download/2025.07.31/platform-espressif32.zip
framework = arduino
```
## Hybrid compile: Build customized Arduino IDF libraries
Adding the option `custom_sdkconfig` in an `[env]` will compile the Arduino libraries using the sdkconfig settings
from the framework and adds the changes specified in `custom_sdkconfig`. After the compile run the Arduino project `[env]` is
compiled with the customized libraries.

Example: Switching off PPP modem support only for `[env:esp32-no-PPP]`
```
[env:esp32-no-PPP]
board = esp32dev
custom_sdkconfig = '# CONFIG_LWIP_PPP_SUPPORT is not set'
```
```
[env:esp32solo1]
board = esp32-solo1
```
The released frameworks can be downloaded [here](https://github.com/tasmota/arduino-esp32/releases)

# Configuration

Please navigate to [documentation](http://docs.platformio.org/page/platforms/espressif32.html).

