// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
//
//       Author  :   Sem van Langen
//       Filename:   pca9685.cpp
//       Part of :   iPass
//
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

#include "pca9685.hpp"

pca9685::pca9685(hwlib::i2c_bus& bus) :
bus(bus)
{set_freq(25, 50);}

void pca9685::write(uint8_t sub_register, uint8_t content_register){
    {
        hwlib::i2c_write_transaction wtrans = ((hwlib::i2c_bus * )(&bus))->write(address_slave);
        hwlib::wait_ns(500);
        wtrans.write(sub_register);
        hwlib::wait_ns(500);
        wtrans.write(content_register);
    }
    hwlib::cout << address_slave << ", " << sub_register << ", " << content_register << hwlib::endl;
    hwlib::wait_ms(50);
}


void pca9685::read(uint8_t sub_register) {
    {
        auto writer = bus.write(address_slave);
        hwlib::wait_ns(500);
        writer.prepare_repeated_start();
        hwlib::wait_ns(500);
        writer.write(sub_register);
        hwlib::wait_ns(500);
    }
    auto read_data = bus.read(address_slave).read_byte();
    hwlib::wait_ns(500);
    hwlib::cout << read_data << hwlib::endl;
}


int pca9685::calculate_freq(int osc_clock_mhz, int update_rate_hz) {
    return (osc_clock_mhz * 1000000 / (4096 * update_rate_hz) - 1);
}


void pca9685::set_freq(int osc_clock_mhz, int update_rate){
    // First I calculate my PWM frequency
    int pwm_freq = calculate_freq(osc_clock_mhz, update_rate);
    // see page 15 of datasheet

    // Then I set my MODE1 to sleep in order to control the PRE_SCALE
    hwlib::wait_ms(500);
    write(MODE1_reg, MODE1_reg_sleep);
    read(MODE1_reg);
    hwlib::wait_ms(500);

    // Then I set my PRE_SCALE
    write(PRE_SCALE_reg, pwm_freq);
    read(PRE_SCALE_reg);
    hwlib::wait_ms(500);

    // Then I set my MODE1 back to normal mode
    write(MODE1_reg, (MODE1_reg_normal));
    read(MODE1_reg);
    hwlib::wait_ms(500);
}


uint16_t pca9685::calculate_counts(uint16_t position, uint8_t max_degrees){
    // I have decided I wanted a 10% delay, so the formula is:
    // min 5% and max 10% of 4095
    // min = 4095 * 0.025 = 103
    // max = 4095 * 0.125 = 511
    // usable_cycle = 408;
    return ((position * (408 / max_degrees)) + 103);
}

void pca9685::set_position_servo(uint16_t position, const servo & led) {
    uint16_t tics_high = 0;
    if (position <= led.max_range && position >= 0) {
        tics_high = calculate_counts(position, led.max_range);
    } else if (position < 0) {
        tics_high = 103;
    } else {
        tics_high = 511;
    }

    hwlib::cout << "TICS_HIGH: " << tics_high << hwlib::endl;

    uint8_t led_on_l_content = 0;
    uint8_t led_on_h_content = 0;

    uint8_t led_off_l_content = led_on_l_content + tics_high;
    uint8_t led_off_h_content = led_on_h_content + (tics_high >> 8);

    hwlib::cout << "Data in subregister ON:" << hwlib::endl;
    write(led.LED_ON_L, led_on_l_content);
    read(led.LED_ON_L);

    write(led.LED_ON_H, led_on_h_content);
    read(led.LED_ON_H);

    hwlib::cout << "Data in subregister OFF:" << hwlib::endl;
    write(led.LED_OFF_L, led_off_l_content);
    read(led.LED_OFF_L);

    write(led.LED_OFF_H, led_off_h_content);
    read(led.LED_OFF_H);
}