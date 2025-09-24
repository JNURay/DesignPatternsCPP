// Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
// This file is part of DesignPatternsCPP.
// Licensed under the MIT License.
// See <https://opensource.org/licenses/MIT>.

#ifndef ADAPTER_TARGET_INTERFACE_HPP
#define ADAPTER_TARGET_INTERFACE_HPP

#include <string>

class TennisScoring
{
public:
    virtual void addPlayer1Scores() = 0;
    virtual void addPlayer2Scores() = 0;
    virtual std::string getScore() = 0;
    virtual ~TennisScoring() = default;
};

#endif // ADAPTER_TARGET_INTERFACE_HPP
