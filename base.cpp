#include "base.hpp"

pca9685::pca9685(hwlib::i2c_bus& bus) :
bus(bus)
{set_freq(25, 50);}

void pca9685::write(int sub_register, int content_register){
        auto write_trans = bus.write(address_slave);
        write_trans.write(sub_register);
        write_trans.write(content_register);
        hwlib::cout << "Slave address, sub register, register content: " << address_slave << ", " << sub_register << ", " << content_register << hwlib::endl;
}


void pca9685::read(int sub_register) {
    uint8_t results[1];
    {
        hwlib::i2c_read_transaction read_trans = bus.read(address_slave);
        read_trans.read(results, 1);
    }

    uint8_t value = results[0];
    hwlib::cout << "Final register content: " << value << hwlib::endl;
}


int pca9685::pwm_calc_freq(int osc_clock_mhz, int update_rate_hz) {
    return (osc_clock_mhz * 1000000 / (4096 * update_rate_hz) - 1);
}


void pca9685::set_freq(int osc_clock_mhz, int update_rate){
    // First I calculate my PWM frequency
    int pwm_freq = pwm_calc_freq(osc_clock_mhz, update_rate);
    // see page 15 of datasheet

    // Then I set my MODE1 to sleep in order to control the PRE_SCALE
    write(MODE1_reg, MODE1_reg_sleep);
    read(MODE1_reg);
    hwlib::wait_ns(500);

    // Then I set my PRE_SCALE
    write(PRE_SCALE_reg, pwm_freq);
    read(PRE_SCALE_reg);

    // Then I set my MODE1 back to normal mode
    write(MODE1_reg, (MODE1_reg_normal));
    read(MODE1_reg);
    hwlib::wait_ns(500);
}


uint16_t pca9685::pwm_control(int zero_to_120_degree){
    // Ive decided i wanted a 5% delay.
    // 4095 * 0.1 = 409.5, 4095 - 409.5 = 3685.5, 3685.5 / 120 = 30.7125
    float one_degree = 30.7125;
    return (zero_to_120_degree * one_degree);
}

void pca9685::set_pwm_led(int zero_to_120_degree, uint8_t subreg_on_l, uint8_t subreg_on_h, uint8_t subreg_off_l, uint8_t subreg_off_h){
    uint16_t temp = pwm_control(zero_to_120_degree);
    hwlib::cout << "\n" << temp << hwlib::endl;
    uint8_t led_off_l = temp;
    uint8_t led_off_h = (temp >> 8);

    hwlib::cout << "Data in subregister ON:" << hwlib::endl;
    write(subreg_on_h, standard_led_on_h);
    read(standard_led_on_h);

    write(subreg_on_l, standard_led_on_l);
    read(standard_led_on_l);

    hwlib::cout << "Data in subregister OFF:" << hwlib::endl;
    write(subreg_off_h, led_off_h);
    read(subreg_off_h);

    write(subreg_off_l, led_off_l);
    read(subreg_off_l);
}
