// Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
// This file is part of DesignPatternsCPP.
// Licensed under the MIT License.
// See <https://opensource.org/licenses/MIT>.

#include "tennis_coach.hpp"
#include "control_racket_manufacturer.hpp"
#include "powerful_racket_manufactor.hpp"

int main() {
    TennisCoach coach{};

    // Create a ControlRacketManufacturer
    std::shared_ptr<TennisRacketManufacturer> controlManufacturer = std::make_shared<ControlRacketManufacturer>();
    coach.assembleRacket(controlManufacturer);
    const auto controlRacket = controlManufacturer->getTennisRacket();
    controlRacket->display();

    // Create a PowerfulRacketManufacturer
    std::shared_ptr<TennisRacketManufacturer> powerfulManufacturer = std::make_shared<PowerfulRacketManufacturer>();
    coach.assembleRacket(powerfulManufacturer);
    const auto powerfulRacket = powerfulManufacturer->getTennisRacket();
    powerfulRacket->display();

    return 0;
}
