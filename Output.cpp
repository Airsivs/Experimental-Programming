#include "MainHeader.h"
#include <iostream>
#include <cstdint>
#include <string_view> 
#include <thread>
#include <chrono>

template <typename T>
constexpr T constAbs(T x)
{
    return (x < 0 ? -x : x);
}


constexpr bool approximatelyEqualRel(double a, double b, double relEpsilon)
{
    return (constAbs(a - b) <= (std::max(constAbs(a), constAbs(b)) * relEpsilon));
};

void OutputPremature(userInput& O){


    for (int i = 0; i < 5; i++){

        system("cls");

        std::cout << "======VEKTORWERK TELEMETRY======" << '\n';
        std::cout << "Selected Simulation time: " << O.simulationTime << '\n';
        std::cout << "Selected Coolant Temperature: " << O.coolantTemperature << '\n';
        std::cout << "Selected steering angle: " << O.steeringAngle << '\n';

        if (O.BrakeFaultAcitivty == 1 || O.BrakeFaultAcitivty == 0) {
            std::cout << "Brake fault activity: " << std::boolalpha << static_cast<bool>(O.BrakeFaultAcitivty) << '\n';
        } else {
            std::cout << "Brake fault activity: INVALID INPUT\n";
        }

        if (O.ManualOverideActivity == 1 || O.ManualOverideActivity == 0) {
            std::cout << "Manual Override Activity: " << std::boolalpha << static_cast<bool>(O.ManualOverideActivity) << '\n';
        } else {
            std::cout << "Manual Override Activity: INVALID INPUT\n";
        }
        std::cout << "(Simulation starting in " << 5 - i << ")" << '\n';
        std::this_thread::sleep_for(std::chrono::seconds(1));
        
    }

    if (O.coolantTemperature > 70 && approximatelyEqualRel(O.steeringAngle, 0.0, 1.0) && O.BrakeFaultAcitivty == 0 && O.ManualOverideActivity == 0){
        system("cls");
        std::cout << "System meets all requirements... Starting simulation...";
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    else {
        system("cls");
        std::cout << "System doesn't meet the requirements. Closing software.";
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
}

void Output(drivetrainNew& N, int tick, userInput& O){

    bool CoolantCheck{};
    if (O.coolantTemperature >= 70){
        CoolantCheck = 1;
    }
    else{
        CoolantCheck = 0;
    }

    bool SteeringAngleCheck{};
    if (approximatelyEqualRel(O.steeringAngle, 0.0, 2.0)){
        SteeringAngleCheck = 1;
    }
    else {
        SteeringAngleCheck = 0;
    }

    std::cout << "=================== VEKTORWERK TELEMETRY [TICK #" << tick << "]===================" << '\n';
    std::cout << "[DRIVETRAIN] RPM: " << N.RPM << " | Calculated gear slot: " << N.gear << " | Shift reccommendation: " << N.recommendation <<'\n';

    std::cout << "[CRUISE CONTROL] Target: " << N.targetSpeed << " km/h | Sensor: " << N.speed << " km/h" << '\n';
    std::cout << "- Direct (==) Check result:   " << std::boolalpha << N.DirectComparison << " (False negative due to FP precision)" <<'\n';
    std::cout << "- Epsilon (|DIFF| < 1e-4):    " << std::boolalpha << N.EpsilonComparison << " (Target Speed Exceeded)" << '\n';
    
    std::cout << '\n';
    std::cout << "[LAUNCH CONTROL]" << '\n';
    std::cout << "- Coolant Temp (> 70.0 C):    " << std::boolalpha << CoolantCheck << " ( " << O.coolantTemperature << " C)" << '\n';
    std::cout << "- Steering angle (~0.0 deg):  " << std::boolalpha << SteeringAngleCheck << " ( " << O.steeringAngle << " deg)" << '\n';
    std::cout << "- Brake safety check:         " << std::boolalpha << O.BrakeFaultAcitivty << '\n';

    bool launchLock{};
    if (SteeringAngleCheck == 1 && CoolantCheck == 1 && O.BrakeFaultAcitivty == 0){
        std::cout << "-> LAUNCH CONTROL STATUS:     SYSTEM READY";
    }
    else{std::cout << "-> LAUNCH CONTROL STATUS:     SYSTEM LOCKED";}

}


