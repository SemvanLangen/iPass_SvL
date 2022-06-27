#include <hwlib.hpp>
#include "pca9685.hpp"
#include "pca9685_constants.hpp"

int main(){
    // TODO zorg dat alle waardes goed uitgelezen worden van LED
    // TODO zoek uit wat ENUM C++ is, tip van Nick voor de LEDS
//    pca9685::servo LED0 = {0x06, 0x07, 0x08, 0x09};
//    pca9685::servo LED1 = {0x0A, 0x0B, 0x0C, 0x0D};
//    pca9685::servo LED2 = {0x0E, 0x0F, 0x10, 0x11};
//    pca9685::servo LED3 = {0x12, 0x13, 0x14, 0x15};
//    pca9685::servo LED4 = {0x16, 0x17, 0x18, 0x19};
//    pca9685::servo LED5 = {0x1A, 0x1B, 0x1C, 0x1D};
//    pca9685::servo LED6 = {0x1E, 0x1F, 0x20, 0x21};
//    pca9685::servo LED7 = {0x22, 0x23, 0x24, 0x25};

    // Declare my bus
    hwlib::target::pin_oc scl = hwlib::target::pin_oc(hwlib::target::pins::d8);
    hwlib::target::pin_oc sda = hwlib::target::pin_oc(hwlib::target::pins::d9);
    hwlib::i2c_bus_bit_banged_scl_sda bus = hwlib::i2c_bus_bit_banged_scl_sda(scl, sda);

    // Make a object and do what I want with it
    pca9685 a(bus);
    for(;;) {
        a.set_pwm_led(120, a.LED0);
//        a.set_pwm_led(120, a.LED1);
//        a.set_pwm_led(120, a.LED2);
        hwlib::wait_ms(500);


        a.set_pwm_led(0, a.LED0);
//        a.set_pwm_led(0, a.LED1);
//        a.set_pwm_led(0, a.LED2);
        hwlib::wait_ms(500);
    }
}
