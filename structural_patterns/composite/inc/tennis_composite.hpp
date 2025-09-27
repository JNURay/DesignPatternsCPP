// Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
// This file is part of DesignPatternsCPP.
// Licensed under the MIT License.
// See <https://opensource.org/licenses/MIT>.

#ifndef COMPOSITE_TENNIS_COMPOSITE_HPP
#define COMPOSITE_TENNIS_COMPOSITE_HPP

#include "tennis_component.hpp"

#include <algorithm>
#include <memory>
#include <vector>

class TennisComposite : public TennisComponent
{
public:
    virtual ~TennisComposite() = default;
    void addChild(std::shared_ptr<TennisComponent> child)
    {
        m_children.push_back(child);
    }
    void removeChild(std::shared_ptr<TennisComponent> child)
    {
        m_children.erase(
            std::remove(m_children.begin(), m_children.end(), child),
            m_children.end()
        );
    }
    void showChildren(int indent = 0) const
    {
        for (const auto& child : m_children)
        {
            child->showInfo(indent + 1);
        }
    }
protected:
    std::vector<std::shared_ptr<TennisComponent>> m_children;
};

#endif // COMPOSITE_TENNIS_COMPOSITE_HPP
