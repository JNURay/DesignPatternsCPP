/*
 * Copyright (C) 2025 YANG Rui <yangrui1028@gmail.com>
 *
 * This file is part of DesignPatternsCPP.
 *
 * Licensed under the GNU General Public License v3.0 or later.
 * See <https://www.gnu.org/licenses/>.
 */

#ifndef TENNIS_RACKET_MANUFACTURER_HPP
#define TENNIS_RACKET_MANUFACTURER_HPP

#include "tennis_racket.hpp"

#include <memory>

class TennisRacketManufacturer
{
public:
    TennisRacketManufacturer()
        : tennisRacket(std::make_shared<TennisRacket>())
    {
    }

    virtual void setFrameMaterial() = 0;

    virtual void setStringMaterial() = 0;

    virtual void setGripSize() = 0;

    virtual void setStringTension() = 0;

    virtual void setBalance() = 0;

    std::shared_ptr<TennisRacket> getTennisRacket() const {
        return tennisRacket;
    }

private:
    std::shared_ptr<TennisRacket> tennisRacket;
};

#endif // TENNIS_RACKET_MANUFACTURER_HPP
