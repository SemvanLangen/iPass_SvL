#include "pca9685.hpp"

pca9685::pca9685(hwlib::i2c_bus& bus) :
bus(bus)
{set_freq(25, 50);}


pca9685::servo LED0 = {0x06, 0x07, 0x08, 0x09};
pca9685::servo LED1 = {0x0A, 0x0B, 0x0C, 0x0D};
pca9685::servo LED2 = {0x0E, 0x0F, 0x10, 0x11};
pca9685::servo LED3 = {0x12, 0x13, 0x14, 0x15};
pca9685::servo LED4 = {0x16, 0x17, 0x18, 0x19};
pca9685::servo LED5 = {0x1A, 0x1B, 0x1C, 0x1D};
pca9685::servo LED6 = {0x1E, 0x1F, 0x20, 0x21};
pca9685::servo LED7 = {0x22, 0x23, 0x24, 0x25};


void pca9685::write(int sub_register, int content_register){
        auto write_trans = bus.write(address_slave);
        write_trans.write(sub_register);
        write_trans.write(content_register);
        hwlib::cout << "Slave address, sub register, register content: " << address_slave << ", " << sub_register << ", " << content_register << hwlib::endl;
}


void pca9685::read() {
    uint8_t results[1];
    {
        hwlib::i2c_read_transaction read_trans = bus.read(address_slave);
        read_trans.read(results, 1);
    }

    uint8_t value = results[0];
    hwlib::cout << "Final register content: " << value << hwlib::endl;
}


int pca9685::calculate_freq(int osc_clock_mhz, int update_rate_hz) {
    return (osc_clock_mhz * 1000000 / (4096 * update_rate_hz) - 1);
}


void pca9685::set_freq(int osc_clock_mhz, int update_rate){
    // First I calculate my PWM frequency
    int pwm_freq = calculate_freq(osc_clock_mhz, update_rate);
    // see page 15 of datasheet

    // Then I set my MODE1 to sleep in order to control the PRE_SCALE
    write(MODE1_reg, MODE1_reg_sleep);
    read();
    hwlib::wait_ms(500);

    // Then I set my PRE_SCALE
    write(PRE_SCALE_reg, pwm_freq);
    read();

    // Then I set my MODE1 back to normal mode
    write(MODE1_reg, (MODE1_reg_normal));
    read();
}


uint16_t pca9685::calculate_counts(int zero_to_120_degree){
    // Ive decided i wanted a 5% delay.
    // 4095 * 0.1 = 409.5, 4095 - 409.5 = 3685.5, 3685.5 / 120 = 30.7125
    float one_degree = 30.7125;
    return (zero_to_120_degree * one_degree);
}

void pca9685::set_pwm_led(int zero_to_120_degree, servo led){
    if (zero_to_120_degree <= 4095 && zero_to_120_degree >= 0){
        cycle_tics = calculate_counts(zero_to_120_degree);
    }
    else if (zero_to_120_degree < 0){
        cycle_tics = 0;
    }
    else{
        cycle_tics = 4095;
    }

    hwlib::cout << "\n" << cycle_tics << hwlib::endl;
    uint8_t led_on_l_content = cycle_tics;
    uint8_t led_on_h_content = (cycle_tics >> 8);

    uint8_t led_off_l_content = 4095 - led_on_l_content;
    uint8_t led_off_h_content = 4095 - led_on_h_content;

    hwlib::cout << "Data in subregister ON:" << hwlib::endl;
    write(led.LED_ON_H, led_on_h_content);
    read();

    write(led.LED_ON_L, led_on_l_content);
    read();

    hwlib::cout << "Data in subregister OFF:" << hwlib::endl;
    write(led.LED_OFF_H, led_off_h_content);
    read();

    write(led.LED_OFF_L, led_off_l_content);
    read();
}
