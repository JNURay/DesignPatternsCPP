// Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
// This file is part of DesignPatternsCPP.
// Licensed under the MIT License.
// See <https://opensource.org/licenses/MIT>.

#ifndef PRODUCT_TENNIS_RACKET_HPP
#define PRODUCT_TENNIS_RACKET_HPP

#include <string>
#include <iostream>

class TennisRacket
{
public:
    void display() const {
        std::cout << "Tennis Racket Specifications:" << std::endl;
        std::cout << "Frame Material: " << frameMaterial << std::endl;
        std::cout << "String Material: " << stringMaterial << std::endl;
        std::cout << "Grip Size: " << gripSize << std::endl;
        std::cout << "String Tension: " << stringTension << " lbs" << std::endl;
        std::cout << "Balance: " << balance << std::endl;
    }

    std::string frameMaterial;
    std::string stringMaterial;
    uint8_t gripSize;
    uint8_t stringTension;
    std::string balance;
};

#endif // PRODUCT_TENNIS_RACKET_HPP
