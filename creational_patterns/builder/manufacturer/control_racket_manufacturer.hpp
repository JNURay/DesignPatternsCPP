// Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
// This file is part of DesignPatternsCPP.
// Licensed under the MIT License.
// See <https://opensource.org/licenses/MIT>.

#ifndef CONTROL_RACKET_MANUFACTURER_HPP
#define CONTROL_RACKET_MANUFACTURER_HPP

#include "tennis_racket_manufacturer.hpp"

class ControlRacketManufacturer : public TennisRacketManufacturer
{
public:
    void setFrameMaterial() override {
        getTennisRacket()->frameMaterial = "Aluminum";
    }

    void setStringMaterial() override {
        getTennisRacket()->stringMaterial = "Natural Gut";
    }

    void setGripSize() override {
        getTennisRacket()->gripSize = 3u;
    }

    void setStringTension() override {
        getTennisRacket()->stringTension = 50u;
    }

    void setBalance() override {
        getTennisRacket()->balance = "Even Balance";
    }
};

#endif // CONTROL_RACKET_MANUFACTURER_HPP
