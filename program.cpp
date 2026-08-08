#include "MainHeader.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdint>

int main(){

    userInput Default{0,0.0,0.0,false,false};
    drivetrainPrev DefaultODT{-20,0,1};
    drivetrainNew DefaultNDT{};

    getUserInput(Default);

    OutputPremature(Default);


    system("cls");

    auto [SimTime,ColTemp,SterAngle,BrakeFaultAcitivty,ManualOverideActivity] = Default;

    for (int tick = 1; tick < SimTime+1; tick++){
        updateDriveTrain(DefaultNDT,DefaultODT, tick);
        Output(DefaultNDT,tick,Default);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        DefaultODT.RPM = DefaultNDT.RPM;
        system("cls");
    };

    return 0;
}
