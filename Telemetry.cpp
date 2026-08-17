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


