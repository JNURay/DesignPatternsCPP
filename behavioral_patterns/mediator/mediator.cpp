// Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
// This file is part of DesignPatternsCPP.
// Licensed under the MIT License.
// See <https://opensource.org/licenses/MIT>.

#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Mediator;

// colleague interface
class Participant
{
public:
    Participant(Mediator* m = nullptr)
        : m_mediator{m}
    {
    }
    void setMediator(Mediator* m) { m_mediator = m; }
    virtual ~Participant() = default;
protected:
    Mediator* m_mediator;
};

// mediator interface
class Mediator
{
public:
    virtual void notify(Participant* sender, const std::string& event) = 0;
};

// concrete colleague class
class Player : public Participant
{
public:
    Player(const std::string& n)
        : m_name{n}
    {
    }

    const std::string& getName() const { return m_name; }

    void requestMatch()
    {
        std::cout << "[Player] " << m_name << " requests a match.\n";
        m_mediator->notify(this, "MatchRequest");
    }

    void receiveCourt(const std::string& m_courtName)
    {
        std::cout << "[Player] " << m_name << " assigned to " << m_courtName << ".\n";
    }

    void matchFinished()
    {
        std::cout << "[Player] " << m_name << " finished the match.\n";
        m_mediator->notify(this, "MatchFinished");
    }
private:
    std::string m_name;
};

// concrete colleague class
class Court : public Participant
{
public:
    Court(const std::string& m_name)
        : m_courtName{m_name}
    {
    }

    const std::string& getName() const { return m_courtName; }
    bool isAvailable() const { return m_available; }

    void reserve() { m_available = false; }
    void release() { m_available = true; }
private:
    std::string m_courtName;
    bool m_available{true};
};

// concrete colleague class
class Umpire : public Participant
{
public:
    void startMatch(const std::string& player, const std::string& court)
    {
        std::cout << "[Umpire] Starts match for " << player
                  << " on " << court << ".\n";
    }
};

// concrete mediator class
class MatchMediator : public Mediator
{
public:
    void registerCourt(std::shared_ptr<Court> court)
    {
        m_courts.push_back(court);
        court->setMediator(this);
    }

    void registerUmpire(std::shared_ptr<Umpire> u)
    {
        m_umpire = u;
        m_umpire->setMediator(this);
    }

    void notify(Participant* sender, const std::string& event) override
    {
        if (event == "MatchRequest")
        {
            auto player = dynamic_cast<Player*>(sender);
            std::cout << "[Mediator] Processing match request from " << player->getName() << "...\n";

            for (auto& court : m_courts)
            {
                if (court->isAvailable())
                {
                    court->reserve();
                    player->receiveCourt(court->getName());
                    m_umpire->startMatch(player->getName(), court->getName());
                    std::cout << "[Mediator] Match scheduled successfully.\n\n";
                    return;
                }
            }
            std::cout << "[Mediator] No available courts for " << player->getName() << " right now.\n\n";
        }
        else if (event == "MatchFinished")
        {
            auto player = dynamic_cast<Player*>(sender);
            std::cout << "[Mediator] Received match finished event from " << player->getName() << ".\n";
            for (auto& court : m_courts)
            {
                if (!court->isAvailable())
                {
                    court->release();
                    std::cout << "[Court] " << court->getName() << " is now available.\n\n";
                    break;
                }
            }
        }
    }
private:
    std::vector<std::shared_ptr<Court>> m_courts;
    std::shared_ptr<Umpire> m_umpire;
};

int main()
{
    auto m_mediator = std::make_shared<MatchMediator>();
    auto m_umpire = std::make_shared<Umpire>();
    m_mediator->registerUmpire(m_umpire);

    auto court1 = std::make_shared<Court>("Center Court");
    auto court2 = std::make_shared<Court>("Court 1");
    m_mediator->registerCourt(court1);
    m_mediator->registerCourt(court2);

    Player player1("Federer");
    Player player2("Nadal");
    player1.setMediator(m_mediator.get());
    player2.setMediator(m_mediator.get());

    player1.requestMatch();
    player2.requestMatch();

    player1.matchFinished();

    player2.requestMatch();

    return 0;
}

