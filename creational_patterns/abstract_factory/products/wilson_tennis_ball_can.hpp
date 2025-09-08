// Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
// This file is part of DesignPatternsCPP.
// Licensed under the MIT License.
// See <https://opensource.org/licenses/MIT>.

#ifndef WILSON_TENNIS_BALL_CAN_HPP
#define WILSON_TENNIS_BALL_CAN_HPP

#include "tennis_ball_can.hpp"

#include <iostream>

class WilsonTennisBallCan : public TennisBallCan
{
public:
    void paintCan() override {
        std::cout << "Painting Wilson tennis ball can." << std::endl;
    }
};

#endif // WILSON_TENNIS_BALL_CAN_HPP
