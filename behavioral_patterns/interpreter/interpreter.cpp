// Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
// This file is part of DesignPatternsCPP.
// Licensed under the MIT License.
// See <https://opensource.org/licenses/MIT>.

#include <iostream>
#include <memory>

class Context {};

class Expression
{
public:
    virtual int interpret(Context& context) = 0;
    virtual ~Expression() = default;
};

// TerminalExpression
class Number : public Expression
{
public:
    explicit Number(int v)
        : m_value{v}
    {
    }

    int interpret(Context& context) override
    {
        return m_value;
    }
private:
    int m_value;
};

// NonTerminalExpression
class AddExpression : public Expression
{
public:
    AddExpression(std::shared_ptr<Expression> l, std::shared_ptr<Expression> r)
        : m_left{std::move(l)}, m_right{std::move(r)}
    {
    }

    int interpret(Context& context) override
    {
        return m_left->interpret(context) + m_right->interpret(context);
    }
private:
    std::shared_ptr<Expression> m_left;
    std::shared_ptr<Expression> m_right;
};

// NonTerminalExpression
class SubtractExpression : public Expression
{
public:
    SubtractExpression(std::shared_ptr<Expression> l, std::shared_ptr<Expression> r)
        : m_left{std::move(l)}, m_right{std::move(r)}
    {
    }

    int interpret(Context& context) override
    {
        return m_left->interpret(context) - m_right->interpret(context);
    }
private:
    std::shared_ptr<Expression> m_left;
    std::shared_ptr<Expression> m_right;
};

int main()
{
    // not used in this simple example
    Context context;

    // expression: (5 + 3) - 2
    auto expression = std::make_shared<SubtractExpression>(
        std::make_shared<AddExpression>(
            std::make_shared<Number>(5),
            std::make_shared<Number>(3)
        ),
        std::make_shared<Number>(2)
    );

    int result = expression->interpret(context);
    std::cout << "(5 + 3) - 2 = " << result << std::endl;

    return 0;
}
