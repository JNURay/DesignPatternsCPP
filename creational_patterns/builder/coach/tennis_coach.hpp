/*
 * Copyright (C) 2025 YANG Rui <yangrui1028@gmail.com>
 *
 * This file is part of DesignPatternsCPP.
 *
 * Licensed under the GNU General Public License v3.0 or later.
 * See <https://www.gnu.org/licenses/>.
 */

#ifndef TENNIS_COACH_HPP
#define TENNIS_COACH_HPP

#include "tennis_racket_manufacturer.hpp"

class TennisCoach
{
public:
    void assembleRacket(std::shared_ptr<TennisRacketManufacturer> racketManufacturer) {
        racketManufacturer->setFrameMaterial();
        racketManufacturer->setStringMaterial();
        racketManufacturer->setGripSize();
        racketManufacturer->setStringTension();
        racketManufacturer->setBalance();
    }
};

#endif // TENNIS_COACH_HPP
