#include "MainHeader.h"
#include <iostream>
#include <cstdint>
#include <string_view> 
#include <thread>
#include <bitset>
#include <chrono>
#include <algorithm>

template <typename T>
constexpr T constAbs(T x){
    return (x < 0 ? -x : x);
}

data::input InputFrame(data::input& input){
    using std::cout;
    using std::cin; 

    cout << "===================VEKTORWERK TELEMETRY INPUT FRAME===================\n";
    cout << "Please input the following info:\n";
    
    cout << "Coolant temp (> 70.0 C):   ";
    cin >> input.coolantTemp;
    
    cout << "Steering angle (~0.0 deg): ";
    cin >> input.steeringAngle;
    
    cout << "Brake safety check (0/1):  ";
    cin >> input.brakecheck;

    cout << "Simulation duration (s):  ";
    cin >> input.tickAmount;

    return input; 
};

constexpr bool approximatelyEqualRel(double a,double b,double epsilon){
    return (constAbs(a-b) <= (std::max(constAbs(a), constAbs(b))* epsilon));
};

bool CheckDirect(double a,double b){
    if (a == b){
        return 1;
    }
    else{
        return 0;
    }
}

void OutputFrame(data::package& data, int tick){
    using std::cout;

    cout << "===================VEKTORWERK TELEMETRY [TICK #" << tick << "]===================" << '\n';
    cout << "[DRIVETRAIN] RPM: " << data.RPM << " | Calculated gear slot: " << data.gear << " | Shift recommendation: " << data.recommendation << '\n';
    cout << "[GEAR RATIO] " << data.gearRatio << '\n';
    cout << "[CRUISE CONTROL] Target: " << data.targetspeed << " km/h | Sensor: " << data.sensorspeed << " km/h" << '\n';
    cout << "- Direct (==) Check result: " << CheckDirect(data.targetspeed,data.sensorspeed) << " (False negative due to FP precision)" << '\n';
    cout << "- Epsilon (|DIFF| < 1e-4):  " << approximatelyEqualRel(data.targetspeed, data.sensorspeed,0.1) << " (Target speed exceeded)" << '\n';

    cout << "[LAUNCH CONTROL]" << '\n';
    cout << "- Coolant Temp (> 70.0 C): " << "( 90 C)" << '\n';
    cout << "- Steering angle (~0.0 deg): " << "( 90 C)" << '\n';
    cout << "- Brake safety check: " << "( 90 C)" << '\n';
    cout << "-> LAUNCH CONTROL STATUS: " << '\n';
};