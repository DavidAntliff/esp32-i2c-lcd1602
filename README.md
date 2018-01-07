# esp32-i2c-lcd1602

[![Build Status](https://travis-ci.org/DavidAntliff/esp32-i2c-lcd1602.svg?branch=master)](https://travis-ci.org/DavidAntliff/esp32-i2c-lcd1602)

## Introduction

This component provides useful access functions for the I2C-LCD1602 device, which is compatible with the HD44780 LCD controller. It uses a PCF8574A Remote 8-bit I/O Expander over the I2C bus, allowing the controller to be programmed via I2C using 4-bit mode.

It is written and tested for the [ESP-IDF](https://github.com/espressif/esp-idf) environment, version 2.1, using the xtensa-esp32-elf toolchain (gcc version 5.2.0).

## Dependencies

Requires [esp32-smbus](https://github.com/DavidAntliff/esp32-smbus).

## Example

An example of this component in use can be found at [DavidAntliff/esp32-i2c-lcd1602-example](https://github.com/DavidAntliff/esp32-i2c-lcd1602-example)

## Features

 * ...

## Documentation

Automatically generated API documentation (doxygen) is available [here](https://davidantliff.github.io/esp32-i2c-lcd1602/index.html).

## Source Code

The source is available from [GitHub](https://www.github.com/DavidAntliff/esp32-i2c-lcd1602).

## License

The code in this project is licensed under the MIT license - see LICENSE for details.

## Links

 * [HD44780 datasheet](https://www.sparkfun.com/datasheets/LCD/HD44780.pdf)
 * [PCF8574A Remote 8-bit I/O Expander for I2C Bus](http://www.ti.com/lit/ds/symlink/pcf8574a.pdf)
 * [Espressif IoT Development Framework for ESP32](https://github.com/espressif/esp-idf)
 
## Acknowledgements

 * Based partially on the Arduino [DFRobot sample code](http://www.dfrobot.com/image/data/DFR0154/LiquidCrystal_I2Cv1-1.rar).
 * "SMBus" is a trademark of Intel Corporation.
 * "I2C" is a registered trademark of Phillips Corporation.

## Roadmap

The following features are anticipated but not yet implemented:

 * ...


 
