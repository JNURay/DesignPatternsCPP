// Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
// This file is part of DesignPatternsCPP.
// Licensed under the MIT License.
// See <https://opensource.org/licenses/MIT>.

#include "tennis_composite.hpp"

class TennisPlayer : public TennisComponent
{
public:
    void showInfo(int indent = 0) const override
    {
        printIndent(indent);
        std::cout << "Player: " << m_name << std::endl;
    }
};

class TennisTeam : public TennisComposite
{
public:
    virtual ~TennisTeam() = default;
    void showInfo(int indent = 0) const override
    {
        printIndent(indent);
        std::cout << "Team: " << m_name << std::endl;
        showChildren(indent);
    }
};

class TennisEvent : public TennisComposite
{
public:
    void showInfo(int indent = 0) const override
    {
        printIndent(indent);
        std::cout << "Event: " << m_name << std::endl;
        showChildren(indent);
    }
};

class TennisTournament : public TennisComposite
{
public:
    void showInfo(int indent = 0) const override
    {
        printIndent(indent);
        std::cout << "Tournament: " << m_name << std::endl;
        showChildren(indent);
    }
};

int main()
{
    const auto federer = std::make_shared<TennisPlayer>();
    federer->setName("Roger FEDERER");
    const auto nadal = std::make_shared<TennisPlayer>();
    nadal->setName("Rafael NADAL");
    const auto djokovic = std::make_shared<TennisPlayer>();
    djokovic->setName("Novak DJOKOVIC");
    const auto serena = std::make_shared<TennisPlayer>();
    serena->setName("Serena WILLIAMS");
    const auto venus = std::make_shared<TennisPlayer>();
    venus->setName("Venus WILLIAMS");
    const auto osaka = std::make_shared<TennisPlayer>();
    osaka->setName("Naomi OSAKA");
    const auto wang = std::make_shared<TennisPlayer>();
    wang->setName("WANG Qiang");
    const auto zhang = std::make_shared<TennisPlayer>();
    zhang->setName("ZHANG Shuai");

    auto williamsTeam = std::make_shared<TennisTeam>();
    williamsTeam->setName("WILLIAMS Sisters");
    williamsTeam->addChild(serena);
    williamsTeam->addChild(venus);

    auto asianTeam = std::make_shared<TennisTeam>();
    asianTeam->setName("Asian Team");
    asianTeam->addChild(osaka);
    asianTeam->addChild(wang);

    auto menSingles = std::make_shared<TennisEvent>();
    menSingles->setName("Men's Singles");
    menSingles->addChild(federer);
    menSingles->addChild(nadal);
    menSingles->addChild(djokovic);

    auto womenDoubles = std::make_shared<TennisEvent>();
    womenDoubles->setName("Women's Doubles");
    womenDoubles->addChild(williamsTeam);
    womenDoubles->addChild(asianTeam);

    auto winbledon = std::make_shared<TennisTournament>();
    winbledon->setName("Wimbledon 2026 In Dream");
    winbledon->addChild(menSingles);
    winbledon->addChild(womenDoubles);

    winbledon->showInfo();

    std::cout << "\n Breaking News: WANG Qiang quits the tournament and ZHANG Shuai joins the Asian Team. \n" << std::endl;
    asianTeam->removeChild(wang);
    asianTeam->addChild(zhang);

    winbledon->showInfo();

    return 0;
}
