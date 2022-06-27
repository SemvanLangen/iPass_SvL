#ifndef YOUR_PROJECT_NAME_PCA9685_HPP
#define YOUR_PROJECT_NAME_PCA9685_HPP

#include "hwlib.hpp"
#include "pca9685_constants.hpp"

class pca9685{
private:
    hwlib::i2c_bus& bus;
    uint16_t cycle_tics;

    /// \brief
    /// Basic write function.
    /// \details
    /// Write to static slave address 0x40, then declare which sub register you want to write to, then write the content.
    void write(int sub_register, int content_register);

    /// \brief
    /// Basic read function.
    /// \details
    /// Read the last write transaction that happened on the chip.
    void read();

    /// \brief
    /// Calculate servo frequency.
    /// \details
    /// Formula to calculate de servo frequency.
    int calculate_freq(int osc_clock_mhz, int update_rate);

    /// \brief
    /// Set de MODE1 and PRE_SCALE registers.
    /// \details
    /// Prepare the MODE1 to set the freq of the servo's in PRE_SCALE, after write to PRE_SCALE set MODE1 to output for the LEDS.
    void set_freq(int osc_clock_mhz, int update_rate);

    /// \brief
    /// Calculate the count of the given degree.
    /// \details
    /// Calculate how much counts the chip needs to set a servo to a given degree.
    uint16_t calculate_counts(int zero_to_120_degree);

public:
    explicit pca9685(hwlib::i2c_bus& bus);

    struct servo{
        uint8_t LED_ON_L;
        uint8_t LED_ON_H;
        uint8_t LED_OFF_L;
        uint8_t LED_OFF_H;
    };

    servo LED0, LED1, LED2, LED3, LED4, LED5, LED6, LED7;

    /// \brief
    /// Set a servo to a specific degree.
    /// \details
    /// Set a servo to a specific degree bij using one of the pca9685::LED and a degree you want to set it to.
    void set_pwm_led(int zero_to_120_degree, servo led);
};

#endif