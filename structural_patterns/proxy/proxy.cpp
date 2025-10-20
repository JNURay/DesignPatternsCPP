// Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
// This file is part of DesignPatternsCPP.
// Licensed under the MIT License.
// See <https://opensource.org/licenses/MIT>.

#include <iostream>
#include <string>
#include <memory>

class Court
{
public:
    virtual void book(const std::string& user) = 0;
    virtual ~Court() = default;
};

class TennisCourt : public Court
{
public:
    void book(const std::string& user) override
    {
        std::cout << user << " successfully booked the tennis court!" << std::endl;
    }
};

class CourtProxy : public Court
{
public:
    CourtProxy(std::shared_ptr<TennisCourt> court)
        : m_realCourt{std::move(court)}
    {}

    void book(const std::string& user) override
    {
        std::cout << "Checking booking permission for " << user << "..." << std::endl;
        if (isVIP(user))
        {
            m_realCourt->book(user);
            std::cout << "[Log] " << user << " booked successfully." << std::endl;
        }
        else
        {
            std::cout << "Sorry, only VIPs can book the court." << std::endl;
        }
    }
private:
    bool isVIP(const std::string& user)
    {
        return user == "Federer" || user == "Nadal";
    }
    std::shared_ptr<TennisCourt> m_realCourt;
};

int main()
{
    const auto court = std::make_shared<TennisCourt>();
    CourtProxy proxy(court);

    proxy.book("Federer");
    proxy.book("Djokovic");

    return 0;
}
