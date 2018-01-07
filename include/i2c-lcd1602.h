/*
 * MIT License
 *
 * Copyright (c) 2018 David Antliff
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * @file i2c-lcd1602.h
 * @brief Interface definitions for the ESP32-compatible I2C LCD1602 component.
 *
 * This component provides structures and functions that are useful for communicating with the device.
 *
 * Technically, the LCD1602 device is an I2C not SMBus device, however some SMBus protocols can be used
 * to communicate with the device, so it makes sense to use an SMBus interface to manage communication.
 */

#ifndef I2C_LCD1602_H
#define I2C_LCD1602_H

#include <stdbool.h>
#include "smbus.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Structure containing information related to the SMBus protocol.
 */
typedef struct
{
    bool init;                                    ///< True if struct has been initialised, otherwise false
    smbus_info_t * smbus_info;                    ///< Pointer to associated SMBus info
    uint8_t backlight_flag;                       ///< Non-zero if backlight is to be enabled, otherwise zero
    uint8_t display_control_flags;                ///< Currently active display control flags
    uint8_t entry_mode_flags;                     ///< Currently active entry mode flags
} i2c_lcd1602_info_t;

#define I2C_LCD1602_NUM_ROWS            2
#define I2C_LCD1602_NUM_COLUMNS         40
#define I2C_LCD1602_NUM_VISIBLE_COLUMNS 16

// Special characters for ROM Code A00
#define I2C_LCD1602_CHARACTER_ALPHA        0b11100000
#define I2C_LCD1602_CHARACTER_BETA         0b11100010
#define I2C_LCD1602_CHARACTER_THETA        0b11110010
#define I2C_LCD1602_CHARACTER_PI           0b11110111
#define I2C_LCD1602_CHARACTER_OMEGA        0b11110100
#define I2C_LCD1602_CHARACTER_SIGMA        0b11110110
#define I2C_LCD1602_CHARACTER_INFINITY     0b11110011
#define I2C_LCD1602_CHARACTER_DEGREE       0b11011111
#define I2C_LCD1602_CHARACTER_ARROW_RIGHT  0b01111110
#define I2C_LCD1602_CHARACTER_ARROW_LEFT   0b01111111
#define I2C_LCD1602_CHARACTER_SQUARE       0b11011011
#define I2C_LCD1602_CHARACTER_DOT          0b10100101
#define I2C_LCD1602_CHARACTER_DIVIDE       0b11111101
#define I2C_LCD1602_CHARACTER_BLOCK        0b11111111

/**
 * @brief Construct a new I2C-LCD1602 info instance.
 *        New instance should be initialised before calling other functions.
 * @return Pointer to new device info instance, or NULL if it cannot be created.
 */
i2c_lcd1602_info_t * i2c_lcd1602_malloc(void);

/**
 * @brief Delete an existing I2C-LCD1602 info instance.
 * @param[in,out] tsl2561_info Pointer to I2C-LCD1602 info instance that will be freed and set to NULL.
 */
void i2c_lcd1602_free(i2c_lcd1602_info_t ** tsl2561_info);

/**
 * @brief Initialise a I2C-LCD1602 info instance with the specified SMBus information.
 * @param[in] i2c_lcd1602_info Pointer to I2C-LCD1602 info instance.
 * @param[in] smbus_info Pointer to SMBus info instance.
 */
esp_err_t i2c_lcd1602_init(i2c_lcd1602_info_t * i2c_lcd1602_info, smbus_info_t * smbus_info, bool backlight);

/**
 * TODO
 * Clears entire display (clears DDRAM) and returns cursor to home position.
 */
esp_err_t i2c_lcd1602_clear(const i2c_lcd1602_info_t * i2c_lcd1602_info);

/**
 * TODO
 * Returns cursor to home position. Also resets any display shift that may have occurred.
 * DDRAM is not changed.
 */
esp_err_t i2c_lcd1602_home(const i2c_lcd1602_info_t * i2c_lcd1602_info);

/**
 * TODO
 */
esp_err_t i2c_lcd1602_move_cursor(const i2c_lcd1602_info_t * i2c_lcd1602_info, uint8_t col, uint8_t row);

/**
 * TODO
 */
esp_err_t i2c_lcd1602_set_backlight(i2c_lcd1602_info_t * i2c_lcd1602_info, bool enable);

/**
 * TODO
 */
esp_err_t i2c_lcd1602_set_display(i2c_lcd1602_info_t * i2c_lcd1602_info, bool enable);

/**
 * TODO
 */
esp_err_t i2c_lcd1602_set_cursor(i2c_lcd1602_info_t * i2c_lcd1602_info, bool enable);

/**
 * TODO
 */
esp_err_t i2c_lcd1602_set_blink(i2c_lcd1602_info_t * i2c_lcd1602_info, bool enable);

/**
 * TODO
 */
esp_err_t i2c_lcd1602_set_left_to_right(i2c_lcd1602_info_t * i2c_lcd1602_info);

/**
 * TODO
 */
esp_err_t i2c_lcd1602_set_right_to_left(i2c_lcd1602_info_t * i2c_lcd1602_info);

/**
 * TODO
 * When enabled, text will appear to be right-justified from the cursor position.
 * When disabled, text will appear to be left-justified from the cursor position.
 */
esp_err_t i2c_lcd1602_set_auto_scroll(i2c_lcd1602_info_t * i2c_lcd1602_info, bool enable);

/**
 * TODO
 */
esp_err_t i2c_lcd1602_scroll_display_left(const i2c_lcd1602_info_t * i2c_lcd1602_info);

/**
 * TODO
 */
esp_err_t i2c_lcd1602_scroll_display_right(const i2c_lcd1602_info_t * i2c_lcd1602_info);

/**
 * TODO
 */
esp_err_t i2c_lcd1602_move_cursor_left(const i2c_lcd1602_info_t * i2c_lcd1602_info);

/**
 * TODO
 */
esp_err_t i2c_lcd1602_move_cursor_right(const i2c_lcd1602_info_t * i2c_lcd1602_info);

/**
 * TODO
 */
esp_err_t i2c_lcd1602_create_char(const i2c_lcd1602_info_t * i2c_lcd1602_info, uint8_t index, uint8_t pixelmap[]);

/**
 * TODO
 */
esp_err_t i2c_lcd1602_write_char(const i2c_lcd1602_info_t * i2c_lcd1602_info, uint8_t chr);

/**
 * TODO
 */
esp_err_t i2c_lcd1602_write_string(const i2c_lcd1602_info_t * i2c_lcd1602_info, const char * string);

#ifdef __cplusplus
}
#endif

#endif // I2C_LCD1602_H
