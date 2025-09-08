// Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
// This file is part of DesignPatternsCPP.
// Licensed under the MIT License.
// See <https://opensource.org/licenses/MIT>.

#ifndef WILSON_TENNIS_BALL_HPP
#define WILSON_TENNIS_BALL_HPP

#include "tennis_ball.hpp"

#include <string>
#include <iostream>

class WilsonTennisBall : public TennisBall
{
public:
    void pressurize() override {
        std::cout << "Pressurizing Wilson tennis ball." << std::endl;
    }

    void paintLogo() override {
        std::cout << "Painting Wilson logo on tennis ball." << std::endl;
    }
};


#endif // WILSON_TENNIS_BALL_HPP