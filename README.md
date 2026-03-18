[![Build_special_firmware](https://raw.githubusercontent.com/vshymanskyy/StandWithUkraine/main/banner-direct.svg)](https://github.com/vshymanskyy/StandWithUkraine/blob/main/docs/README.md)


# Tasmota Espressif 32 platform

[![Examples](https://github.com/Jason2866/platform-espressif32/actions/workflows/examples.yml/badge.svg)](https://github.com/Jason2866/platform-espressif32/actions/workflows/examples.yml)[![GitHub Releases](https://img.shields.io/github/downloads/tasmota/platform-espressif32/total?label=downloads)](https://github.com/tasmota/platform-espressif32/releases/latest)

Espressif Systems is a privately held, fabless semiconductor company renowned for delivering cost-effective wireless communication microcontrollers. Their innovative solutions are widely adopted in mobile devices and Internet of Things (IoT) applications around the globe.

## Installation
- [Download and install Microsoft Visual Studio Code](https://code.visualstudio.com/). pioarduino IDE is on top of it.
- Open the extension manager.
- Search for the `pioarduino ide` extension.
- Install pioarduino IDE extension.

## Usage
1. Setup new VSCode pioarduino project.
1. Check the `platform` setting in platformio.ini file:

## Tasmota release Arduino 3.3.7+ and IDF 5.5.3.260313
Support for the ESP32/ESP32solo1, ESP32C2, ESP32C3, ESP32C6, ESP32S2, ESP32S3, ESP32-H2 and ESP32P4 (before rev.300 and rev.300)
```
[platformio]
platform = https://github.com/tasmota/platform-espressif32/releases/download/2026.03.50/platform-espressif32.zip
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
The released frameworks can be downloaded [here](https://github.com/tasmota/arduino-esp32/releases)

# Configuration

Please navigate to [documentation](http://docs.platformio.org/page/platforms/espressif32.html).

# Features

## Filesystem Support

This platform supports two filesystem options:

- **LittleFS** (default) - Wear-leveling filesystem optimized for flash memory
- **FatFS** - Standard FAT filesystem with broad compatibility

### FatFS Integration

FatFS is now fully integrated as a Python module, similar to LittleFS.

**Quick Start:**

```ini
[env:myenv]
board_build.filesystem = fatfs
```

**Available Commands:**

```bash
pio run -t buildfs        # Build FatFS image
pio run -t uploadfs       # Upload FatFS image
pio run -t download_fatfs # Download and extract FatFS from device
```

See the [arduino-fatfs example](examples/arduino-fatfs/) for a complete working example.
