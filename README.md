[![Build_special_firmware](https://raw.githubusercontent.com/vshymanskyy/StandWithUkraine/main/banner-direct.svg)](https://github.com/vshymanskyy/StandWithUkraine/blob/main/docs/README.md)


# Tasmota Espressif 32: development platform for [PlatformIO](http://platformio.org)

[![Examples](https://github.com/Jason2866/platform-espressif32/actions/workflows/examples.yml/badge.svg)](https://github.com/Jason2866/platform-espressif32/actions/workflows/examples.yml)[![GitHub Releases](https://img.shields.io/github/downloads/tasmota/platform-espressif32/total?label=downloads)](https://github.com/tasmota/platform-espressif32/releases/latest)

Espressif Systems is a privately held, fabless semiconductor company renowned for delivering cost-effective wireless communication microcontrollers. Their innovative solutions are widely adopted in mobile devices and Internet of Things (IoT) applications around the globe.

# Usage

1. [Install PlatformIO](http://platformio.org)
2. Create PlatformIO project and configure a platform option in [platformio.ini](http://docs.platformio.org/page/projectconf.html) file:

### Arduino 3.3.4+ and IDF 5.5.1+ (build from development sources)
Support for the ESP32/ESP32solo1, ESP32S2, ESP32S3, ESP32C2, ESP32C3, ESP32C5, ESP32C6, ESP32C61, ESP32-H2 and ESP32-P4

```                  
[platformio]
platform = https://github.com/Jason2866/platform-espressif32.git#Arduino/IDF55
framework = arduino
```

for ESP32 Solo1
```
[env:esp32solo1]
board = esp32-solo1
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

FatFS is now fully integrated as a Python module, similar to LittleFS. See [FATFS_INTEGRATION.md](FATFS_INTEGRATION.md) for detailed documentation.

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
