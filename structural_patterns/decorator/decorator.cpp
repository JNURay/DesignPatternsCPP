// Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
// This file is part of DesignPatternsCPP.
// Licensed under the MIT License.
// See <https://opensource.org/licenses/MIT>.

#include "tennis_racket_decorator.hpp"

int main()
{
    std::shared_ptr<TennisRacketComponent> racket = std::make_shared<TennisRacketComponent>();
    std::cout << "Base Racket:" << std::endl;
    racket->getDescription();
    std::cout << "\nCost: $" << racket->cost() << std::endl;

    racket = std::make_shared<VibrationDampenerDecorator>(racket);
    std::cout << "\nAfter adding Vibration Dampener:" << std::endl;
    racket->getDescription();
    std::cout << "\nCost: $" << racket->cost() << std::endl;

    racket = std::make_shared<GripDecorator>(racket);
    std::cout << "\nAfter adding Anti-Slip Grip:" << std::endl;
    racket->getDescription();
    std::cout << "\nCost: $" << racket->cost() << std::endl;

    return 0;
}