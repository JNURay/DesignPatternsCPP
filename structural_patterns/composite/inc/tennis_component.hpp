// Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
// This file is part of DesignPatternsCPP.
// Licensed under the MIT License.
// See <https://opensource.org/licenses/MIT>.

#ifndef COMPOSITE_TENNIS_COMPONENT_HPP
#define COMPOSITE_TENNIS_COMPONENT_HPP

#include <iostream>
#include <string>

class TennisComponent
{
public:
    virtual ~TennisComponent() = default;
    virtual void showInfo(int indent = 0) const = 0;
    std::string getName() const { return m_name; }
    void setName(const std::string& name) { m_name = name; }
protected:
    std::string m_name;
    void printIndent(int indent) const
    {
        for (int i = 0; i < indent; ++i)
        {
            std::cout << "  ";
        }
    }
};

#endif // COMPOSITE_TENNIS_COMPONENT_HPP
