#pragma once
#include <cstdint>
#include <string>
#include <algorithm>

struct userInput {
    int simulationTime{};
    double coolantTemperature{};
    double steeringAngle{};
    bool BrakeFaultAcitivty{};
    bool ManualOverideActivity{};
};

struct drivetrainPrev {
    int RPM{};
    double speed{};
    int gear{};
    int targetSpeed{};
    bool DirectComparison{};
    bool EpsilonComparison{};
    std::string recommendation{};
};

struct drivetrainNew {
    int RPM{};
    double speed{};
    int gear{};;
    int targetSpeed{};
    bool DirectComparison{};
    bool EpsilonComparison{};
    std::string recommendation{};
};


void getUserInput(userInput& UI);
void OutputPremature(userInput& O);
void updateDriveTrain(drivetrainNew& N, drivetrainPrev& O, int tick);
void Output(drivetrainNew& N, int tick, userInput& O);
constexpr bool approximatelyEqualRel(double a, double b, double relEpsilon);