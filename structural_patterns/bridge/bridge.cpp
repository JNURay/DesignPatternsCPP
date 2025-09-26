// Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
// This file is part of DesignPatternsCPP.
// Licensed under the MIT License.
// See <https://opensource.org/licenses/MIT>.

#include "tennis_match.hpp"

class StandardScoring : public ScoringSystem
{
public:
    void score() override {
        std::cout << "Scoring with standard rule, first to 6 sets with advantage" << std::endl;
    }
};

class Fast4Scoring : public ScoringSystem
{
public:
    void score() override {
        std::cout << "Scoring with Fast4 rule, first to 4 sets with no advantage" << std::endl;
    }
};

class SinglesMatch : public TennisMatch
{
public:
    using TennisMatch::TennisMatch;
    void play() override {
        std::cout << "Playing singles match. "<< std::endl;
        scoringSystem->score();
    }
};

class DoublesMatch : public TennisMatch
{
public:
    using TennisMatch::TennisMatch;
    void play() override {
        std::cout << "Playing doubles match. "<< std::endl;
        scoringSystem->score();
    }
};

int main()
{
    const auto standardScoring = std::make_shared<StandardScoring>();
    const auto fast4Scoring = std::make_shared<Fast4Scoring>();

    const auto singlesWithStandard = std::make_unique<SinglesMatch>(standardScoring);
    singlesWithStandard->play();
    const auto singlesWithFast4 = std::make_unique<SinglesMatch>(fast4Scoring);
    singlesWithFast4->play();
    const auto doublesWithStandard = std::make_unique<DoublesMatch>(standardScoring);
    doublesWithStandard->play();
    const auto doublesWithFast4 = std::make_unique<DoublesMatch>(fast4Scoring);
    doublesWithFast4->play();

    return 0;
}
