#include "MainHeader.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdint>

int main(){

    Initialize();
    logFrame(modeRegister);
    FormatPayload(modeRegister);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    Frame2BitManip(modeRegister);
    logFrame(modeRegister);
    FormatPayload(modeRegister);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    Frame3BitManip(modeRegister);
    logFrame(modeRegister);
    FormatPayload(modeRegister);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    logFrame(modeRegister);
    FormatPayload(modeRegister);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    Frame5BitManip(modeRegister);
    logFrame(modeRegister);
    FormatPayload(modeRegister);
    EndTelemetry();
    return 0;
    
}