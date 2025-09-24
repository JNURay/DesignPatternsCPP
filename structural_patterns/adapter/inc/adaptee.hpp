// Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
// This file is part of DesignPatternsCPP.
// Licensed under the MIT License.
// See <https://opensource.org/licenses/MIT>.

#ifndef ADAPTER_ADAPTEE_HPP
#define ADAPTER_ADAPTEE_HPP

class NumericScoring
{
public:
    NumericScoring() = default;

    void addPointToPlayer1() { player1Points++; }
    void addPointToPlayer2() { player2Points++; }

    int getPlayer1Points() const { return player1Points; }
    int getPlayer2Points() const { return player2Points; }

protected:
    int player1Points{0};
    int player2Points{0};
};

#endif // ADAPTER_ADAPTEE_HPP
