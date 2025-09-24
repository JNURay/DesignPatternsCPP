// Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
// This file is part of DesignPatternsCPP.
// Licensed under the MIT License.
// See <https://opensource.org/licenses/MIT>.

#include "adaptee.hpp"
#include "target_interface.hpp"

#include <iostream>
#include <memory>
#include <string>

class ScoringAdapter : public TennisScoring
{
public:
    explicit ScoringAdapter(NumericScoring* numeric)
        : numericSystem(numeric)
    {}

    void addPlayer1Scores() override { numericSystem->addPointToPlayer1(); }
    void addPlayer2Scores() override { numericSystem->addPointToPlayer2(); }

    std::string getScore() override {
        int p1 = numericSystem->getPlayer1Points();
        int p2 = numericSystem->getPlayer2Points();

        if (p1 >= 3 && p2 >= 3) {
            if (p1 == p2) return "Deuce";
            if (p1 == p2 + 1) return "Advantage Player1";
            if (p2 == p1 + 1) return "Advantage Player2";
        }

        return convert(p1) + " - " + convert(p2);
    }

private:
    NumericScoring* numericSystem;

    std::string convert(int points) {
        switch(points) {
            case 0: return "0";
            case 1: return "15";
            case 2: return "30";
            case 3: return "40";
            default: return "40+";
        }
    }
};

int main()
{
    std::cout << "Object Adapter Pattern Demo" << std::endl;

    NumericScoring numericSystem;
    const auto scoring = std::make_unique<ScoringAdapter>(&numericSystem);

    scoring->addPlayer1Scores();
    std::cout << scoring->getScore() << std::endl;  // 15 - 0

    scoring->addPlayer2Scores();
    scoring->addPlayer2Scores();
    std::cout << scoring->getScore() << std::endl;  // 15 - 30

    scoring->addPlayer1Scores();
    scoring->addPlayer1Scores();
    std::cout << scoring->getScore() << std::endl;  // 40 - 30

    scoring->addPlayer2Scores();
    std::cout << scoring->getScore() << std::endl;  // Deuce

    scoring->addPlayer1Scores();
    std::cout << scoring->getScore() << std::endl;  // Advantage Player1

    return 0;
}
