// Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
// This file is part of DesignPatternsCPP.
// Licensed under the MIT License.
// See <https://opensource.org/licenses/MIT>.

#ifndef BRIDGE_TENNIS_MATCH_HPP
#define BRIDGE_TENNIS_MATCH_HPP

#include "scoring_system.hpp"

#include <memory>

class TennisMatch
{
public:
    TennisMatch(std::shared_ptr<ScoringSystem> scoring) : scoringSystem{scoring} {}
    virtual void play() = 0;
    virtual ~TennisMatch() = default;
protected:
    std::shared_ptr<ScoringSystem> scoringSystem;
};

#endif // BRIDGE_TENNIS_MATCH_HPP
