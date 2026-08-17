#include "MainHeader.h"
#include <iostream>
#include <cstdint>
#include <string_view> 
#include <thread>
#include <bitset>
#include <chrono>

namespace{
    constexpr int increaseG1{1000};
    constexpr int increaseG2{600};
    constexpr int increaseG3{300};
    constexpr int increaseG4{200};
    constexpr int increaseG56{150};
    constexpr int turboGain{180};
    //---------------------------
    constexpr double gearRatioG1{4.06};
    constexpr double gearRatioG2{2.40};
    constexpr double gearRatioG3{1.58};
    constexpr double gearRatioG4{1.19};
    constexpr double gearRatioG56{0.9};
}

template <typename T>
constexpr T constAbs(T x){
    return (x < 0 ? -x : x);
}

constexpr bool approximatelyEqualRel(double a,double b,double epsilon){
    return (constAbs(a-b) <= (std::max(constAbs(a), constAbs(b))* epsilon));
};

data::inputConversion BoolCheck(data::inputConversion& input, data::input& convert){

    if(convert.coolantTemp>70){
        input.CoolantBool = 1;
    }
    else{
        input.CoolantBool = 0;
    }

    if(approximatelyEqualRel(convert.steeringAngle,0.0,0.1)){
        input.SteeringBool = 1;
    }
    else{
        input.SteeringBool = 0;
    }

    if(convert.brakecheck==1){
        input.brakeCheck = 1;
    }
    else{
        input.brakeCheck = 0;
    }

    input.coolantTempBool = convert.coolantTemp;
    input.steeringAngleBool = convert.steeringAngle;

    system("cls");
    using std::cout;
    cout << "=============VEKTORWERK TELEMETRY=============" << '\n';
    cout << "DEBUG: " << '\n';
    cout << std::boolalpha << "Coolant temp - " << input.CoolantBool << '\n';
    cout << "Steering angle - " << input.SteeringBool << '\n';
    cout << "Brake check - " << input.SteeringBool << '\n';

    if (input.brakeCheck == 1 & input.CoolantBool == 1 & input.SteeringBool == 1){
        input.launchState = 1;
        cout << "[FINAL LAUNCH STATE]: " << input.launchState;
        std::this_thread::sleep_for(std::chrono::seconds(5));
        system("cls");
        cout << "STARTING SIMULATION..." << '\n';
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    else{
        input.launchState = 0;
        cout << "[FINAL LAUNCH STATE]: " << input.launchState;
        std::this_thread::sleep_for(std::chrono::seconds(5));
        system("cls");
        cout << "CLOSING SIMULATION";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::exit(0);
    }
    
    cout << "Starting this dumpster fire" << '\n';
    system("cls");
    return input;
}



data::package Drivetrain(data::package& data){

    int realRPM;

    switch(data.gear){
        case 1:
            realRPM = data.RPM + increaseG1 + turboGain;
            data.gearRatio = gearRatioG1;
            break;
        case 2:
            realRPM = data.RPM + increaseG2 + turboGain;
            data.gearRatio = gearRatioG2;
            break;
        case 3:
            realRPM = data.RPM + increaseG3 + turboGain;
            data.gearRatio = gearRatioG3;
            break;
        case 4:
            realRPM = data.RPM + increaseG4 + turboGain;
            data.gearRatio = gearRatioG4;
            break;
        default:
            realRPM = data.RPM + increaseG56 + turboGain;
            data.gearRatio = gearRatioG56;
            break;
    }

    data.RPM = realRPM;

    if (data.RPM < 6000 & data.RPM > 2000){
        data.recommendation = "OPTIMAL";
    }
    if (data.RPM > 6000){
        data.recommendation = "UP-SHIFT";
    }
    else{
        data.recommendation = "DOWNSHIFT";
    }

    if (data.RPM > 7000 & data.gear <=6){
        data.RPM = 2400;
        ++data.gear;
    }
    
    

    return data;

}


