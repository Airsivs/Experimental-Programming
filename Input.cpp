#include "MainHeader.h"
#include <iostream>
#include <cstdint>

void getUserInput(userInput& UI){

    std::cout << "=========VEKTORWERK TELEMETRY==========" << '\n';
    std::cout << "Please input the following data: " << '\n';
    std::cout << '\n';
    std::cout << "Simulation time (s): ";
    std::cin >> UI.simulationTime;
    std::cout << '\n';
    std::cout << "Coolant temperature (C): ";
    std::cin >> UI.coolantTemperature;
    std::cout << '\n';
    std::cout << "Steering angle (degrees): ";
    std::cin >> UI.steeringAngle;
    std::cout << '\n';
    std::cout << "Brake fault activity (0 - false, 1 - true): ";
    std::cin >> UI.BrakeFaultAcitivty;
    std::cout << '\n';
    std::cout << "Manual Override Activity (0 - false, 1 - true): ";
    std::cin >> UI.ManualOverideActivity;
};