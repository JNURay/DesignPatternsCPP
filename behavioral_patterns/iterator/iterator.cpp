// Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
// This file is part of DesignPatternsCPP.
// Licensed under the MIT License.
// See <https://opensource.org/licenses/MIT>.

#include <iostream>
#include <vector>
#include <string>
#include <memory>

class Iterator
{
public:
    virtual bool hasNext() = 0;
    virtual std::string next() = 0;
    virtual ~Iterator() = default;
};

class Aggregate
{
public:
    virtual std::unique_ptr<Iterator> createIterator() = 0;
    virtual ~Aggregate() = default;
};

// concrete aggregate
class TennisCamp : public Aggregate
{
public:
    void addPlayer(const std::string& name)
    {
        m_players.push_back(name);
    }

    const std::vector<std::string>& getPlayers() const
    {
        return m_players;
    }

    std::unique_ptr<Iterator> createIterator() override;
private:
    std::vector<std::string> m_players;
};

// concrete iterator
class PlayerIterator : public Iterator
{
public:
    PlayerIterator(const std::vector<std::string>& players)
        : m_players{players}
    {
    }

    bool hasNext() override
    {
        return index < m_players.size();
    }

    std::string next() override
    {
        return m_players[index++];
    }
private:
    const std::vector<std::string>& m_players;
    size_t index = 0;
};

// TennisCamp creates its specific iterator
std::unique_ptr<Iterator> TennisCamp::createIterator()
{
    return std::make_unique<PlayerIterator>(m_players);
}

int main()
{
    TennisCamp camp;
    camp.addPlayer("Roger Federer");
    camp.addPlayer("Rafael Nadal");
    camp.addPlayer("Novak Djokovic");

    auto it = camp.createIterator();
    while (it->hasNext())
    {
        std::cout << "Player: " << it->next() << std::endl;
    }

    return 0;
}
