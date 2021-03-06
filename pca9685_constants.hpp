// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
//
//       Author  :   Sem van Langen
//       Filename:   pca9685_constants.cpp
//       Part of :   iPass
//
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

#ifndef YOUR_PROJECT_NAME_PCA9685_CONSTANTS_HPP
#define YOUR_PROJECT_NAME_PCA9685_CONSTANTS_HPP

// slave address
constexpr int address_slave                 = 0x40;

// MODE1 status
constexpr uint8_t MODE1_reg                 = 0x00;
constexpr uint8_t MODE1_reg_sleep           = 0x11; // 0x91
constexpr uint8_t MODE1_reg_normal          = 0x81; // 0x01

// prescale register location
constexpr uint8_t PRE_SCALE_reg             = 0xFE;

#endif
