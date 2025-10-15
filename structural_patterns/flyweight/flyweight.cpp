// Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
// This file is part of DesignPatternsCPP.
// Licensed under the MIT License.
// See <https://opensource.org/licenses/MIT>.

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>

class TennisFlyweight
{
public:
    virtual void draw(const std::string& position) const = 0;
    virtual ~TennisFlyweight() = default;
};

class ConcreteTennisBall : public TennisFlyweight
{
public:
    ConcreteTennisBall(std::string brand, std::string color)
        : m_brand{std::move(brand)}
        , m_color{std::move(color)}
    {
    }

    void draw(const std::string& position) const override
    {
        std::cout << "🎾 Draw " << m_color << " " << m_brand
                    << " ball at " << position << '\n';
    }

private:
    std::string m_brand;
    std::string m_color;
};

class TennisBallBucket : public TennisFlyweight
{
public:
    void addBall(const std::shared_ptr<TennisFlyweight>& ball)
    {
        m_balls.push_back(ball);
    }

    void draw(const std::string& area) const override
    {
        std::cout << "🧺 Drawing bucket in " << area << ":\n";
        for (const auto& ball : m_balls) {
            ball->draw(area + " (bucketed)");
        }
    }

private:
    std::vector<std::shared_ptr<TennisFlyweight>> m_balls;
};

class TennisBallFactory
{
public:
    std::shared_ptr<TennisFlyweight> getBall(const std::string& brand, const std::string& color)
    {
        std::string key = brand + "_" + color;
        auto it = m_balls.find(key);
        if (it == m_balls.end())
        {
            std::cout << "🆕 Creating new tennis ball: " << key << '\n';
            auto newBall = std::make_shared<ConcreteTennisBall>(brand, color);
            m_balls[key] = newBall;
            return newBall;
        }
        return it->second;
    }

private:
    std::unordered_map<std::string, std::shared_ptr<TennisFlyweight>> m_balls;
};

int main()
{
    TennisBallFactory factory;

    const auto wilsonYellow = factory.getBall("Wilson", "Yellow");
    const auto dunlopWhite  = factory.getBall("Dunlop", "White");

    const auto anotherYellowWilson = factory.getBall("Wilson", "Yellow");
    const auto anotherWhiteWilson = factory.getBall("Wilson", "White");

    wilsonYellow->draw("at (10,20)");
    anotherYellowWilson->draw("at (15,25)");
    anotherWhiteWilson->draw("at (30,25)");
    dunlopWhite->draw("at (30,40)");

    auto bucket = std::make_shared<TennisBallBucket>();
    bucket->addBall(wilsonYellow);
    bucket->addBall(anotherWhiteWilson);
    bucket->addBall(dunlopWhite);

    bucket->draw("Court A");

    return 0;
}
