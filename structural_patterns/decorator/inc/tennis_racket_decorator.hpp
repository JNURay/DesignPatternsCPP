// Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
// This file is part of DesignPatternsCPP.
// Licensed under the MIT License.
// See <https://opensource.org/licenses/MIT>.

#ifndef DECORATOR_TENNIS_RACKET_DECORATOR_HPP
#define DECORATOR_TENNIS_RACKET_DECORATOR_HPP

#include "tennis_racket_component.hpp"

#include <memory>

class RacketDecorator : public TennisRacketComponent
{
public:
    explicit RacketDecorator(std::shared_ptr<TennisRacketComponent> racket)
        : m_racket(std::move(racket))
    {
    }
protected:
    std::shared_ptr<TennisRacketComponent> m_racket;
};

class VibrationDampenerDecorator : public RacketDecorator
{
public:
    using RacketDecorator::RacketDecorator;

    void getDescription() const override
    {
        m_racket->getDescription();
        std::cout << " + vibration dampener";
    }

    double cost() const override {
        return m_racket->cost() + 30.0;
    }
};

class GripDecorator : public RacketDecorator
{
public:
    using RacketDecorator::RacketDecorator;

    void getDescription() const override {
        m_racket->getDescription();
        std::cout << " + anti-slip grip";
    }

    double cost() const override {
        return m_racket->cost() + 50.0;
    }
};

#endif // DECORATOR_TENNIS_RACKET_DECORATOR_HPP
