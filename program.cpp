#include "profiler.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdint>

void maxTheoreticalSpeed(){
    constexpr double earthGravity {9.81};
    constexpr int maximumSafeRPM {7000};
    constexpr int idlingRPM {600};
    constexpr double gearRatioMax {4.17};
    constexpr int inputTorque {500};

    constexpr double outputTorque {inputTorque*gearRatioMax*0.90};
    constexpr double enginePower {(idlingRPM*outputTorque)/9.549};

    constexpr double airDensity {1.225};
    constexpr double dragCoefficient {0.30};
    constexpr double frontAreaHood {2.17};

    constexpr long double maxTheoreticalSpeed {((2*enginePower)/(airDensity*dragCoefficient*frontAreaHood))/0.33};

    std::cout <<  "Max theoretical speed: " << maxTheoreticalSpeed << " M/S (calculation is wrong)" << '\n';
}

void CheckOilWarn(double oilLevel){

    system("cls");
    std::cout << "CHECK OIL LIGHT; OIL LEVEL BELOW THRESHOLD" << '\n';
    std::cout << "CURRENT OIL LEVEL: " << oilLevel << '\n';

};

void ABSwarn(int StatedSpeed){

    for (int i = StatedSpeed; StatedSpeed >= 1; StatedSpeed -=5){
        system("cls");
        std::cout << "ABS INITIATED; SPEED DROP SIGNIFICANT." << '\n';
        std::cout << "CURRENT SPEED: " << StatedSpeed;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

};

void CheckEngineWarn(int CurrentRPM, int maximumSafeRPM){

    system("cls");

    std::cout << "CHECK ENGINE LIGHT; RPM LIMIT EXCEEDED - " << maximumSafeRPM << '\n';
    std::cout << "CURRENT RPM: " << CurrentRPM << '\n';

};

int main(){
    constexpr int maximumSafeRPM {7000};

    maxTheoreticalSpeed();

    const uint16_t WHEEL_SPEED_ADDRESS = 0x100; 

    double oilLevel {0.7};
    uint16_t RPM {700};
    uint8_t Speed {40};
    uint8_t PrevSpeed {50};

    if (PrevSpeed-Speed > 30){
        ABSwarn(Speed);
    }

    if (RPM > maximumSafeRPM){
        CheckEngineWarn(RPM, maximumSafeRPM);
    }

    if (oilLevel < 1){
        CheckOilWarn(oilLevel);
    }

    return 0;
}
