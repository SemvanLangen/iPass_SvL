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

#include "robo_spooder.hpp"


robo_spooder::robo_spooder(pca9685 &object) :
    object(object)
{}

void robo_spooder::neutral(){
    object.set_position_servo(90, LED_STRUCT::LED0);
    object.set_position_servo(90, LED_STRUCT::LED4);
    object.set_position_servo(90, LED_STRUCT::LED8);
    object.set_position_servo(90, LED_STRUCT::LED12);

    object.set_position_servo(0, LED_STRUCT::LED1);
    object.set_position_servo(180, LED_STRUCT::LED5);
    object.set_position_servo(0, LED_STRUCT::LED9);
    object.set_position_servo(180, LED_STRUCT::LED13);
}

void robo_spooder::wave() {
    object.set_position_servo(0, LED_STRUCT::LED5);
    hwlib::wait_ms(200);

    for (unsigned int i = 0; i < 2; i++) {
        object.set_position_servo(100, LED_STRUCT::LED4);
        hwlib::wait_ms(200);
        object.set_position_servo(60, LED_STRUCT::LED4);
        hwlib::wait_ms(200);
    }

    hwlib::wait_ms(200);
    object.set_position_servo(180, LED_STRUCT::LED5);
    hwlib::wait_ms(200);
}

void robo_spooder::bow_down(){
    neutral();
    hwlib::wait_ms(100);

    object.set_position_servo(100, LED_STRUCT::LED1);
    object.set_position_servo(100, LED_STRUCT::LED5);
    hwlib::wait_ms(3000);

    object.set_position_servo(180, LED_STRUCT::LED1);
    object.set_position_servo(180, LED_STRUCT::LED5);
}

void robo_spooder::test_all(){
    //body front left
    object.set_position_servo(90, LED_STRUCT::LED0);
    hwlib::wait_ms(200);
    //leg front left
    object.set_position_servo(90, LED_STRUCT::LED1);
    hwlib::wait_ms(200);

    // body front right
    object.set_position_servo(90, LED_STRUCT::LED4);
    hwlib::wait_ms(200);
    // legs front right
    object.set_position_servo(90, LED_STRUCT::LED5);
    hwlib::wait_ms(200);

    // body bottom left
    object.set_position_servo(90, LED_STRUCT::LED8);
    hwlib::wait_ms(200);
    // leg bottom left
    object.set_position_servo(90, LED_STRUCT::LED9);
    hwlib::wait_ms(200);

    // body bottom right
    object.set_position_servo(90, LED_STRUCT::LED12);
    hwlib::wait_ms(200);
    // leg bottom right
    object.set_position_servo(90, LED_STRUCT::LED13);
    hwlib::wait_ms(200);
}

void robo_spooder::demo(){
    neutral();
    wave();
    hwlib::wait_ms(1000);
    neutral();
    test_all();
    hwlib::wait_ms(1000);
    neutral();
    bow_down();
    hwlib::wait_ms(1000);
}