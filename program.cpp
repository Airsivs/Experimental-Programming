#include "MainHeader.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdint>

static int Tick{0};

int main(){

    std::string projectVer{"0.1.1"};

    data::input myInput{};
    data::package DrivetrainPackage{};
    myInput = InputFrame(myInput);
    DrivetrainPackage.gear = 1;
    system("cls");
    FlagCheck(myInput);

    for (; Tick < myInput.tickAmount+1; Tick++){
        Drivetrain(DrivetrainPackage);
        OutputFrame(DrivetrainPackage, Tick, myInput,projectVer);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("cls");
    }

    EndStatistics(Tick);

    return 0;
    
}