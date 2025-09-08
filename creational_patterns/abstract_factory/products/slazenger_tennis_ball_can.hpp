// Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
// This file is part of DesignPatternsCPP.
// Licensed under the MIT License.
// See <https://opensource.org/licenses/MIT>.

#ifndef SLAZENGER_TENNIS_BALL_CAN_HPP
#define SLAZENGER_TENNIS_BALL_CAN_HPP

#include "tennis_ball_can.hpp"

#include <iostream>

class SlazengerTennisBallCan : public TennisBallCan
{
public:
    void paintCan() override {
        std::cout << "Painting Slazenger tennis ball can." << std::endl;
    }
};



#endif // SLAZENGER_TENNIS_BALL_CAN_HPP