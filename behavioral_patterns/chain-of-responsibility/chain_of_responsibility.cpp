// Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
// This file is part of DesignPatternsCPP.
// Licensed under the MIT License.
// See <https://opensource.org/licenses/MIT>.

#include <iostream>
#include <memory>
#include <string>

class MatchEvent
{
public:
    explicit MatchEvent(std::string type)
        : m_type{std::move(type)}
    {
    }
    const std::string& getType() const { return m_type; }
private:
    std::string m_type;
};

class Judge
{
public:
    void setNext(std::shared_ptr<Judge> next)
    {
        m_nextJudge = next;
    }

    virtual void handleEvent(const MatchEvent& event)
    {
        if (m_nextJudge) m_nextJudge->handleEvent(event);
    }

    virtual ~Judge() = default;
protected:
    std::shared_ptr<Judge> m_nextJudge;
};

class LineJudge : public Judge
{
public:
    void handleEvent(const MatchEvent& event) override
    {
        if (event.getType() == "Out" || event.getType() == "Foot Fault")
        {
            std::cout << "Line Judge handles: " << event.getType() << std::endl;
        }
        else if (m_nextJudge)
        {
            m_nextJudge->handleEvent(event);
        }
    }
};

class ChairUmpire : public Judge
{
public:
    void handleEvent(const MatchEvent& event) override
    {
        if (event.getType() == "Dispute")
        {
            std::cout << "Chair Umpire handles: " << event.getType() << std::endl;
        }
        else if (m_nextJudge)
        {
            m_nextJudge->handleEvent(event);
        }
    }
};

class Referee : public Judge
{
public:
    void handleEvent(const MatchEvent& event) override
    {
        std::cout << "Referee makes final decision on: " << event.getType() << std::endl;
    }
};

int main()
{
    const auto lineJudge = std::make_shared<LineJudge>();
    const auto chairUmpire = std::make_shared<ChairUmpire>();
    const auto referee = std::make_shared<Referee>();

    lineJudge->setNext(chairUmpire);
    chairUmpire->setNext(referee);

    MatchEvent e1("Out");
    MatchEvent e2("Dispute");
    MatchEvent e3("Player Appeal");

    lineJudge->handleEvent(e1);
    lineJudge->handleEvent(e2);
    lineJudge->handleEvent(e3);
}
