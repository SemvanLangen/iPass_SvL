#ifndef YOUR_PROJECT_NAME_ROBO_SPOODER_HPP
#define YOUR_PROJECT_NAME_ROBO_SPOODER_HPP

#include "pca9685.hpp"

pca9685 prepare_bus(){
    hwlib::target::pin_oc scl = hwlib::target::pin_oc(hwlib::target::pins::d8);
    hwlib::target::pin_oc sda = hwlib::target::pin_oc(hwlib::target::pins::d9);
    hwlib::i2c_bus_bit_banged_scl_sda bus = hwlib::i2c_bus_bit_banged_scl_sda(scl, sda);
    pca9685 object(bus);
}


void neutral_state(pca9685 object){
    object = prepare_bus();
    object.set_pwm_led(60, object.LED0);
    object.set_pwm_led(60, object.LED1);
    object.set_pwm_led(60, object.LED2);
    object.set_pwm_led(60, object.LED3);

    hwlib::wait_ms(500);

    object.set_pwm_led(120, object.LED0);
    object.set_pwm_led(120, object.LED1);
    object.set_pwm_led(120, object.LED2);
    object.set_pwm_led(120, object.LED3);
}


void bow_down(pca9685 object){
    object = prepare_bus();
    object.set_pwm_led(120, object.LED4);
    object.set_pwm_led(120, object.LED5);

    hwlib::wait_ms(2000);

    object.set_pwm_led(0, object.LED4);
    object.set_pwm_led(0, object.LED5);
}


void step_forward(pca9685 object){
    object = prepare_bus();
}

#endif