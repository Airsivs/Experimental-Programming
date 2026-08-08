#include "MainHeader.h"
#include <iostream>
#include <cstdint>
#include <cmath>
#include <algorithm>

void updateDriveTrain(drivetrainNew& N, drivetrainPrev& O, int tick){

    if (tick == 0) {
        N.speed = 0.0;
        N.gear = 1;
        N.RPM = 0.0;
        return;
    }

    double gearRatio{};

    double calc {-0.62 * tick};
    double euler{std::exp(calc)}; 
    N.speed = 100.0 * (1.0 - euler) * std::pow(tick / 5.0, 0.3);

    if (N.speed < 59.0){
        N.gear = 1;
        gearRatio = 4.17;
    }
    else if (N.speed < 105.2){
        N.gear = 2;
        gearRatio = 2.34;
    }
    else if (N.speed < 161.9){
        N.gear = 3;
        gearRatio = 1.52;
    }
    else if (N.speed < 215.9){
        N.gear = 4;
        gearRatio = 1.14;
    }
    else if (N.speed < 282.9){
        N.gear = 5;
        gearRatio = 0.87;
    }
    else {
        N.gear = 6;
        gearRatio = 0.69;
    }

    if (N.speed < 20.0 && N.gear == 1) {
        N.RPM = 2500.0 + ((N.speed / 20.0) * 1000.0);
    } else {
        N.RPM = (N.speed * gearRatio * 3.46 * 208.8) / 25.4;
        
        if (N.RPM > 7000.0) {
            N.RPM = 7000.0;
        }
    }

    N.recommendation =  (N.RPM > 6500) ? "UP-SHIFT" : 
                        (N.RPM < 1800) ? "DOWN-SHIFT" : "OPTIMAL";

    N.targetSpeed = static_cast<int>(N.speed);

    if (N.targetSpeed == N.speed){
        N.DirectComparison = 1;
    }
    else {
        N.DirectComparison = 0;
    }

    if (approximatelyEqualRel(N.speed, N.targetSpeed, 1)){
        N.EpsilonComparison = 1;
    }
    else{
        N.EpsilonComparison = 0;
    }
}

