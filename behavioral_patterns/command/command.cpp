// Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
// This file is part of DesignPatternsCPP.
// Licensed under the MIT License.
// See <https://opensource.org/licenses/MIT>.

#include <iostream>
#include <vector>
#include <memory>

// Receiver
class Player
{
public:
    void serve()
    {
        std::cout << "Player serves the ball!" << std::endl;
    }
    void hit()
    {
        std::cout << "Player hits the ball!" << std::endl;
    }
};

class Command
{
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
};

class ServeCommand : public Command
{
public:
    ServeCommand(Player* p)
        : m_player{p}
    {
    }
    void execute() override { m_player->serve(); }
private:
    Player* m_player;
};

class HitCommand : public Command
{
public:
    HitCommand(Player* p)
        : m_player{p}
    {
    }
    void execute() override { m_player->hit(); }
private:
    Player* m_player;
};

// Invoker
class Coach
{
public:
    void addCommand(std::shared_ptr<Command> cmd)
    {
        m_commands.push_back(cmd);
    }

    void executeCommands()
    {
        for (auto& cmd : m_commands)
        {
            cmd->execute();
        }
        m_commands.clear();
    }
private:
    std::vector<std::shared_ptr<Command>> m_commands;
};

// Client
int main()
{
    Player player;

    auto serve = std::make_shared<ServeCommand>(&player);
    auto hit = std::make_shared<HitCommand>(&player);

    Coach coach;
    coach.addCommand(serve);
    coach.addCommand(hit);

    coach.executeCommands();

    return 0;
}
