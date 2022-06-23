#include <hwlib.hpp>
#include "base.hpp"
#include "pca9685_constants.hpp"

int main(){
// test function of write / read base
    hwlib::target::pin_oc scl = hwlib::target::pin_oc(hwlib::target::pins::d8);
    hwlib::target::pin_oc sda = hwlib::target::pin_oc(hwlib::target::pins::d9);
    hwlib::i2c_bus_bit_banged_scl_sda bus = hwlib::i2c_bus_bit_banged_scl_sda(scl, sda);

    pca9685 a(bus);
    a.set_pwm_led(60, LED0_ON_L, LED0_ON_H, LED0_OFF_L, LED0_OFF_H);


//    a.write(0x00, 0x11);
//    a.read(0x00);
//    hwlib::cout << a.pwm_calc_freq(25, 50) << hwlib::endl;
//    a.set_freq(25, 50);
//    hwlib::cout << a.pwm_control(60) << hwlib::endl;
//    a.set_pwm_led(60, LED0_ON_L, LED0_ON_H, LED0_OFF_L, LED0_OFF_H);
}
