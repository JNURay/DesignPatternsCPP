// Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
// This file is part of DesignPatternsCPP.
// Licensed under the MIT License.
// See <https://opensource.org/licenses/MIT>.

#ifndef BRIDGE_SCORING_SYSTEM_HPP
#define BRIDGE_SCORING_SYSTEM_HPP

#include <iostream>

class ScoringSystem
{
public:
    virtual ~ScoringSystem() = default;
    virtual void score() = 0;
};

#endif // BRIDGE_SCORING_SYSTEM_HPP
