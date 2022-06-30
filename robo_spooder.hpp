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

#ifndef YOUR_PROJECT_NAME_ROBO_SPOODER_HPP
#define YOUR_PROJECT_NAME_ROBO_SPOODER_HPP

#include "pca9685.hpp"

void wave(pca9685& object);
void bow_down(pca9685& object);
void test_all(pca9685& object);

#endif