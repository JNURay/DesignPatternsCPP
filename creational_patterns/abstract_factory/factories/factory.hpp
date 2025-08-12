/*
 * Copyright (C) 2025 YANG Rui <yangrui1028@gmail.com>
 *
 * This file is part of DesignPatternsCPP.
 *
 * Licensed under the GNU General Public License v3.0 or later.
 * See <https://www.gnu.org/licenses/>.
 */

#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "tennis_ball.hpp"
#include "tennis_ball_can.hpp"

#include <memory>

class Factory
{
public:
    virtual std::unique_ptr<TennisBall> makeTennisBall() = 0;
    virtual std::unique_ptr<TennisBallCan> makeTennisBallCan() = 0;
};

#endif // FACTORY_HPP