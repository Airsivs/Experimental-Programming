#include "MainHeader.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdint>

static int Tick{0};

int main(){

    data::input myInput{};
    data::package DrivetrainPackage{};
    data::inputConversion InputConversionStart{};
    myInput = InputFrame(myInput);
    DrivetrainPackage.gear = 1;
    system("cls");
    BoolCheck(InputConversionStart,myInput);
    
    for (; Tick < myInput.tickAmount+1; Tick++){
        Drivetrain(DrivetrainPackage);
        OutputFrame(DrivetrainPackage, Tick, InputConversionStart);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("cls");
    }

    return 0;
    
}