// Copyright (c) 2025 YANG Rui <yangrui1028@gmail.com>
// This file is part of DesignPatternsCPP.
// Licensed under the MIT License.
// See <https://opensource.org/licenses/MIT>.

#include <iostream>

class CameraSystem
{
public:
    void turnOn() { std::cout << "Camera: ON\n"; }
    void turnOff() { std::cout << "Camera: OFF\n"; }
};

class AudioSystem
{
public:
    void start() { std::cout << "Audio: ON\n"; }
    void stop() { std::cout << "Audio: OFF\n"; }
};

class LightingSystem
{
public:
    void setMatchMode() { std::cout << "Lighting: Match Mode\n"; }
    void setOff() { std::cout << "Lighting: OFF\n"; }
};

class ScoreboardSystem
{
public:
    void showStartScreen() { std::cout << "Scoreboard: Ready\n"; }
    void showEndScreen() { std::cout << "Scoreboard: Final Score\n"; }
};

class TennisMatchFacade
{
public:
    void startMatch() {
        camera.turnOn();
        audio.start();
        light.setMatchMode();
        scoreboard.showStartScreen();
        std::cout << "🏆 Match Started!\n";
    }

    void endMatch() {
        scoreboard.showEndScreen();
        light.setOff();
        audio.stop();
        camera.turnOff();
        std::cout << "🏁 Match Ended!\n";
    }

private:
    CameraSystem camera;
    AudioSystem audio;
    LightingSystem light;
    ScoreboardSystem scoreboard;
};

int main()
{
    TennisMatchFacade match;
    match.startMatch();
    match.endMatch();
    return 0;
}
