// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
//
//       Author  :   Sem van Langen
//       Filename:   robo_spooder.cpp
//       Part of :   iPass
//
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

#include "pca9685.hpp"

void neutral(pca9685& object){
    object.set_position_servo(140, LED_STRUCT::LED0);
    hwlib::wait_ms(100);
    object.set_position_servo(40, LED_STRUCT::LED0);
    hwlib::wait_ms(100);
    object.set_position_servo(140, LED_STRUCT::LED0);
    hwlib::wait_ms(100);
    object.set_position_servo(40, LED_STRUCT::LED0);
    hwlib::wait_ms(100);
}

void wave(pca9685& object) {
    object.set_position_servo(130, LED_STRUCT::LED5);
    hwlib::wait_ms(200);

    for (unsigned int i = 0; i < 2; i++) {
        object.set_position_servo(180, LED_STRUCT::LED4);
        hwlib::wait_ms(200);
        object.set_position_servo(90, LED_STRUCT::LED4);
        hwlib::wait_ms(200);
    }

    object.set_position_servo(180, LED_STRUCT::LED5);
    hwlib::wait_ms(200);
}

void bow_down(pca9685& object){
    object.set_position_servo(90, LED_STRUCT::LED4);
    object.set_position_servo(90, LED_STRUCT::LED5);
    hwlib::wait_ms(200);

    object.set_position_servo(180, LED_STRUCT::LED4);
    object.set_position_servo(180, LED_STRUCT::LED5);
    hwlib::wait_ms(200);
}

void test_all(pca9685& object){
    //body front left
    object.set_position_servo(90, LED_STRUCT::LED0);
    hwlib::wait_ms(200);
    //leg front left
    object.set_position_servo(180, LED_STRUCT::LED1);
    hwlib::wait_ms(200);

    // body front right
    object.set_position_servo(90, LED_STRUCT::LED4);
    hwlib::wait_ms(200);
    // legs front right
    object.set_position_servo(180, LED_STRUCT::LED5);
    hwlib::wait_ms(200);

    // body bottom left
    object.set_position_servo(90, LED_STRUCT::LED8);
    hwlib::wait_ms(200);
    // leg bottom left
    object.set_position_servo(180, LED_STRUCT::LED9);
    hwlib::wait_ms(200);

    // body bottom right
    object.set_position_servo(90, LED_STRUCT::LED12);
    hwlib::wait_ms(200);
    // leg bottom right
    object.set_position_servo(180, LED_STRUCT::LED13);
    hwlib::wait_ms(200);
}