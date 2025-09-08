// Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
// This file is part of DesignPatternsCPP.
// Licensed under the MIT License.
// See <https://opensource.org/licenses/MIT>.

#ifndef SLAZENGER_FACTORY_HPP
#define SLAZENGER_FACTORY_HPP

#include "factory.hpp"
#include "slazenger_tennis_ball.hpp"
#include "slazenger_tennis_ball_can.hpp"

class SlazengerFactory : public Factory
{
public:
    std::unique_ptr<TennisBall> makeTennisBall() override {
        std::unique_ptr<TennisBall> ball = std::make_unique<SlazengerTennisBall>();
        ball->pressurize();
        ball->paintLogo();
        return ball;
    }

    std::unique_ptr<TennisBallCan> makeTennisBallCan() override {
        std::unique_ptr<TennisBallCan> can = std::make_unique<SlazengerTennisBallCan>();
        can->paintCan();
        return can;
    }
};


#endif // SLAZENGER_FACTORY_HPP
