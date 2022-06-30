// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
//
//       Author  :   Sem van Langen
//       Filename:   pca9685.hpp
//       Part of :   iPass
//
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

#ifndef YOUR_PROJECT_NAME_PCA9685_HPP
#define YOUR_PROJECT_NAME_PCA9685_HPP

#include "hwlib.hpp"
#include "pca9685_constants.hpp"

/// \brief
/// Struct for register adresses.
/// \details
/// Struct for all the register adresses.
struct servo{
    uint8_t LED_ON_L;
    uint8_t LED_ON_H;
    uint8_t LED_OFF_L;
    uint8_t LED_OFF_H;
    uint8_t max_range = 180;
};

struct LED_STRUCT {
    static constexpr const servo LED0 = {0x06, 0x07, 0x08, 0x09};
    static constexpr const servo LED1 = {0x0A, 0x0B, 0x0C, 0x0D};
    static constexpr const servo LED2 = {0x0E, 0x0F, 0x10, 0x11};
    static constexpr const servo LED3 = {0x12, 0x13, 0x14, 0x15};

    static constexpr const servo LED4 = {0x16, 0x17, 0x18, 0x19};
    static constexpr const servo LED5 = {0x1A, 0x1B, 0x1C, 0x1D};
    static constexpr const servo LED6 = {0x1E, 0x1F, 0x20, 0x21};
    static constexpr const servo LED7 = {0x22, 0x23, 0x24, 0x25};

    static constexpr const servo LED8 = {0x26, 0x27, 0x28, 0x29};
    static constexpr const servo LED9 = {0x2A, 0x2B, 0x2C, 0x2D};
    static constexpr const servo LED10 = {0x2E, 0x2F, 0x30, 0x31};
    static constexpr const servo LED11 = {0x32, 0x33, 0x34, 0x35};

    static constexpr const servo LED12 = {0x36, 0x37, 0x38, 0x39};
    static constexpr const servo LED13 = {0x3A, 0x3B, 0x3C, 0x3D};
    static constexpr const servo LED14 = {0x3E, 0x3F, 0x40, 0x41};
    static constexpr const servo LED15 = {0x42, 0x43, 0x44, 0x45};
};

class pca9685{
private:
    hwlib::i2c_bus& bus;
    uint16_t cycle_tics;

    /// \brief
    /// Basic write function.
    /// \details
    /// Write to static slave address 0x40, then declare which sub register you want to write to, then write the content.
    void write(uint8_t register_address, uint8_t data);

    /// \brief
    /// Basic read function.
    /// \details
    /// Read the last write transaction that happened on the chip.
    void read(uint8_t register_address);

    /// \brief
    /// Calculate servo frequency.
    /// \details
    /// Formula to calculate de servo frequency.
    int calculate_freq(int osc_clock_mhz, int update_rate);

    /// \brief
    /// Calculate the count of the given degree.
    /// \details
    /// Calculate how much counts the chip needs to set a servo to a given degree.
    uint16_t calculate_counts(uint16_t position, uint8_t max_degrees);

public:
    explicit pca9685(hwlib::i2c_bus& bus);

    /// \brief
    /// Set de MODE1 and PRE_SCALE registers.
    /// \details
    /// Prepare the MODE1 to set the freq of the servo's in PRE_SCALE, after write to PRE_SCALE set MODE1 to output for the LEDS.
    void set_freq(int osc_clock_mhz, int update_rate);

    /// \brief
    /// Set a servo to a specific degree.
    /// \details
    /// Set a servo to a specific degree bij using one of the pca9685::LED and a degree you want to set it to.
    void set_position_servo(uint16_t position, const servo & led);
};

#endif