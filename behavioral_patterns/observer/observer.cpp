// Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
// This file is part of DesignPatternsCPP.
// Licensed under the MIT License.
// See <https://opensource.org/licenses/MIT>.

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

class Observer
{
public:
    virtual void update(const std::string& score) = 0;
    virtual ~Observer() = default;
};

class Subject
{
public:
    virtual void attach(std::shared_ptr<Observer> observer) = 0;
    virtual void detach(std::shared_ptr<Observer> observer) = 0;
    virtual void notify() = 0;
    virtual ~Subject() = default;
};

class TennisMatch : public Subject
{
public:
    void attach(std::shared_ptr<Observer> observer) override
    {
        m_observers.push_back(observer);
    }

    void detach(std::shared_ptr<Observer> observer) override
    {
        m_observers.erase(
            std::remove(m_observers.begin(), m_observers.end(), observer),
            m_observers.end());
    }

    void notify() override
    {
        for (auto& obs : m_observers)
        {
            obs->update(m_score);
        }
    }

    void setScore(const std::string& newScore)
    {
        m_score = newScore;
        notify();
    }
private:
    std::vector<std::shared_ptr<Observer>> m_observers;
    std::string m_score;

};

class Scoreboard : public Observer
{
public:
    void update(const std::string& score) override
    {
        std::cout << "[Scoreboard] current score: " << score << std::endl;
    }
};

class AudienceDisplay : public Observer
{
public:
    void update(const std::string& score) override
    {
        std::cout << "[AudienceDisplay] audience sees score update: " << score << std::endl;
    }
};

class Commentator : public Observer
{
public:
    void update(const std::string& score) override
    {
        std::cout << "[Commentator] commentator: score updated to " << score << std::endl;
    }
};

int main()
{
    // Create a tennis match (subject)
    TennisMatch match;

    // Create observers
    auto board = std::make_shared<Scoreboard>();
    auto display = std::make_shared<AudienceDisplay>();
    auto commentator = std::make_shared<Commentator>();

    // Subscribe to the match
    match.attach(board);
    match.attach(display);
    match.attach(commentator);

    // Match process
    match.setScore("30-15");
    match.setScore("40-15");
    match.setScore("Game Player A");

    return 0;
}
