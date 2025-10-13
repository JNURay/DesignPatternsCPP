// Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
// This file is part of DesignPatternsCPP.
// Licensed under the MIT License.
// See <https://opensource.org/licenses/MIT>.

#ifndef DECORATOR_TENNIS_RACKET_COMPONENT_HPP
#define DECORATOR_TENNIS_RACKET_COMPONENT_HPP

#include <iostream>
#include <string>

class TennisRacketComponent
{
public:
    virtual ~TennisRacketComponent() = default;
    virtual void getDescription() const
    {
        std::cout << "A Basic Racket";
    }
    virtual double cost() const
    {
        return 500.0; // Base cost of the racket
    }
};

#endif // DECORATOR_TENNIS_RACKET_COMPONENT_HPP
