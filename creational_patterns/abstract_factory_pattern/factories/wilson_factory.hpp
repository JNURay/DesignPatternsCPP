/*
 * Copyright (C) 2025 YANG Rui <yangrui1028@gmail.com>
 *
 * This file is part of DesignPatternsCPP.
 *
 * Licensed under the GNU General Public License v3.0 or later.
 * See <https://www.gnu.org/licenses/>.
 */

#ifndef WILSON_FACTORY_HPP
#define WILSON_FACTORY_HPP

#include "factory.hpp"
#include "wilson_tennis_ball.hpp"
#include "wilson_tennis_ball_can.hpp"

class WilsonFactory : public Factory
{
public:
    std::unique_ptr<TennisBall> makeTennisBall() override {
        std::unique_ptr<TennisBall> ball = std::make_unique<WilsonTennisBall>();
        ball->pressurize();
        ball->paintLogo();
        return ball;
    }

    std::unique_ptr<TennisBallCan> makeTennisBallCan() override {
        std::unique_ptr<TennisBallCan> can = std::make_unique<WilsonTennisBallCan>();
        can->paintCan();
        return can;
    }
};

#endif // WILSON_FACTORY_HPP
