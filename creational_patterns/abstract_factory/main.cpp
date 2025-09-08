// Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
// This file is part of DesignPatternsCPP.
// Licensed under the MIT License.
// See <https://opensource.org/licenses/MIT>.

#include "slazenger_factory.hpp"
#include "wilson_factory.hpp"

int main() {
    // Create a Slazenger factory
    std::unique_ptr<Factory> slazengerFactory = std::make_unique<SlazengerFactory>();
    std::unique_ptr<TennisBall> slazengerBall = slazengerFactory->makeTennisBall();
    std::unique_ptr<TennisBallCan> slazengerCan = slazengerFactory->makeTennisBallCan();

    // Create a Wilson factory
    std::unique_ptr<Factory> wilsonFactory = std::make_unique<WilsonFactory>();
    std::unique_ptr<TennisBall> wilsonBall = wilsonFactory->makeTennisBall();
    std::unique_ptr<TennisBallCan> wilsonCan = wilsonFactory->makeTennisBallCan();

    return 0;
}
