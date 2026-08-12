#include "MainHeader.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdint>

int main(){

    outputStart(ecuRegister);

    {
        drivetrain::Block1(ecuRegister);
        output(ecuRegister,1,"PRE-LAUNCH");
    }
    std::this_thread::sleep_for(std::chrono::seconds(2));
    {
        drivetrain::Block2(ecuRegister);
        output(ecuRegister,2,"THERMAL FAULT DETECTED");
    }
    std::this_thread::sleep_for(std::chrono::seconds(2));
    {
        drivetrain::Block3(ecuRegister);
        output(ecuRegister,3,"COOL-DOWN & RECOVERY");
    }
    std::this_thread::sleep_for(std::chrono::seconds(10));

    return 0;
}