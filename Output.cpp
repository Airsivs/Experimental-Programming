#include "MainHeader.h"
#include <iostream>
#include <cstdint>
#include <string_view> 
#include <thread>
#include <bitset>
#include <chrono>

namespace{
    int frameCount{0};
}

int FrameCount(){
    ++frameCount;
    return frameCount;
};

void logFrame(std::uint8_t modeRegister){
    std::cout << "[FRAME #" << FrameCount() << "] REGISTER: " << std::bitset<8>(modeRegister) << std::dec << "(Decimal: " << static_cast<int>(modeRegister) << ")" << '\n';

};

void Initialize(){
    using std::cout;
    cout << "=============================================================" << '\n';
    cout << "VEKTORWERK ECU DRIVE-MODE SYSTEM INITIALIZATION" << '\n';
    cout << "=============================================================" << '\n';
}

void EndTelemetry(){
    using std::cout;
    cout << "=============================================================" << '\n';
    cout << "TOTAL TELEMETRY FRAMES LOGGED: " << frameCount << '\n';
    cout << "=============================================================" << '\n';
}