/*
 * Copyright (C) 2025 YANG Rui <yangrui1028@gmail.com>
 *
 * This file is part of DesignPatternsCPP.
 *
 * Licensed under the GNU General Public License v3.0 or later.
 * See <https://www.gnu.org/licenses/>.
 */

#ifndef POWERFUL_RACKET_MANUFACTURER_HPP
#define POWERFUL_RACKET_MANUFACTURER_HPP

#include "tennis_racket_manufacturer.hpp"

class PowerfulRacketManufacturer : public TennisRacketManufacturer
{
public:
    void setFrameMaterial() override {
        getTennisRacket()->frameMaterial = "Graphite";
    }

    void setStringMaterial() override {
        getTennisRacket()->stringMaterial = "Polyester";
    }

    void setGripSize() override {
        getTennisRacket()->gripSize = 4u;
    }

    void setStringTension() override {
        getTennisRacket()->stringTension = 55u;
    }

    void setBalance() override {
        getTennisRacket()->balance = "Head Heavy";
    }
};

#endif // POWERFUL_RACKET_MANUFACTURER_HPP
