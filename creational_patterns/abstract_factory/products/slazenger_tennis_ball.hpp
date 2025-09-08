// Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
// This file is part of DesignPatternsCPP.
// Licensed under the MIT License.
// See <https://opensource.org/licenses/MIT>.

#ifndef SLAZENGER_TENNIS_BALL_HPP
#define SLAZENGER_TENNIS_BALL_HPP

#include "tennis_ball.hpp"

#include <string>
#include <iostream>

class SlazengerTennisBall : public TennisBall
{
public:
    void pressurize() override {
        std::cout << "Pressurizing Slazenger tennis ball." << std::endl;
    }
    void paintLogo() override {
        std::cout << "Painting Slazenger logo on tennis ball." << std::endl;
    }
};

#endif // SLAZENGER_TENNIS_BALL_HPP
