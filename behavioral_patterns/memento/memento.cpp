// Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
// This file is part of DesignPatternsCPP.
// Licensed under the MIT License.
// See <https://opensource.org/licenses/MIT>.

#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Memento
{
public:
    Memento(const std::string& s)
        : m_state{s}
    {
    }
    std::string getState() const { return m_state; }
private:
    std::string m_state;
};

class Originator
{
public:
    void setState(const std::string& s)
    {
        m_state = s;
        std::cout << "current state: " << m_state << std::endl;
    }

    std::shared_ptr<Memento> createMemento()
    {
        return std::make_shared<Memento>(m_state);
    }

    void restoreMemento(const std::shared_ptr<Memento>& memento)
    {
        m_state = memento->getState();
        std::cout << "restored state: " << m_state << std::endl;
    }
private:
    std::string m_state;
};

class Caretaker
{
public:
    void save(const std::shared_ptr<Memento>& memento)
    {
        m_history.push_back(memento);
    }

    std::shared_ptr<Memento> get(size_t index)
    {
        if (index < m_history.size()) return m_history[index];
        return nullptr;
    }
private:
    std::vector<std::shared_ptr<Memento>> m_history;
};

int main()
{
    Originator originator;
    Caretaker caretaker;

    originator.setState("State #1");
    caretaker.save(originator.createMemento());

    originator.setState("State #2");
    caretaker.save(originator.createMemento());

    originator.setState("State #3");

    // restore to 1st state
    originator.restoreMemento(caretaker.get(0)); // restore to State #1
}
