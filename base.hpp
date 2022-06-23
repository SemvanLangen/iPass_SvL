#ifndef YOUR_PROJECT_NAME_BASE_HPP
#define YOUR_PROJECT_NAME_BASE_HPP

#include "hwlib.hpp"
#include "pca9685_constants.hpp"

class pca9685{
private:
    hwlib::i2c_bus& bus;

    void write(uint8_t sub_register, uint8_t content_register);

    void read(uint8_t sub_register);

    int pwm_calc_freq(int osc_clock_mhz, int update_rate);

    void set_freq(int osc_clock_mhz, int update_rate);

public:
    explicit pca9685(hwlib::i2c_bus& bus);

    uint16_t pwm_control(int zero_to_120_degree);

    void set_pwm_led(int zero_to_120_degree, uint8_t subreg_on_l, uint8_t subreg_on_h, uint8_t subreg_off_l, uint8_t subreg_off_h);

//    void set_pwm_60_degree(uint8_t subreg_on_l, uint8_t subreg_on_h, uint8_t subreg_off_l, uint8_t subreg_off_h);
};

#endif