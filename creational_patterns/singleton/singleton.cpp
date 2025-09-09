// Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
// This file is part of DesignPatternsCPP.
// Licensed under the MIT License.
// See <https://opensource.org/licenses/MIT>.

#include <iostream>
#include <memory>

class RogerFederer
{
public:
    static RogerFederer& getInstance() {
        // Since C++11, initialization of local static variables is thread-safe
        static RogerFederer instance;
        return instance;
    }

protected:
    // not accessible, use getInstance() instead
    RogerFederer() = default;
private:
    ~RogerFederer() = default;
    RogerFederer(const RogerFederer&) = delete;
    RogerFederer& operator=(const RogerFederer&) = delete;
};

int main() {
    const auto& rf1 = RogerFederer::getInstance();
    const auto& rf2 = RogerFederer::getInstance();

    if (&rf1 == &rf2) {
        std::cout << "Only one instance exists." << std::endl;
        return 0; // success
    } else {
        std::cout << "Different instances exist!" << std::endl;
        return 1; // fail
    }
}
