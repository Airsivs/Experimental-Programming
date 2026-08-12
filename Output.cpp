#include "MainHeader.h"
#include <iostream>
#include <cstdint>
#include <string_view> 
#include <thread>
#include <bitset>
#include <chrono>



std::string Check(std::uint8_t ecuRegister, std::uint8_t InputFlag){
    return (ecuRegister & InputFlag) ? "X" : " ";
}

void outputStart(std::uint8_t ecuRegister){
    std::cout << "=============================================" << '\n';
    std::cout << "VEKTORWERK SYSTEM INITIALIZATION" << '\n';
    std::cout << "=============================================" << '\n';
    std::cout << '\n';
}

void output(std::uint8_t ecuRegister, int blockNumber, std::string_view eventHappening){
    std::cout << "---[BLOCK " << blockNumber << ": "<< eventHappening <<"]---" << '\n';
    std::cout << "Register: " << std::bitset<8>(ecuRegister) << " | Decimal: " << std::dec << static_cast<int>(ecuRegister)<< '\n';
    std::cout << "[" << Check(ecuRegister, diagnostics::FLAG_LAUNCH_READY) << "] LAUNCH READY" << '\n';
    std::cout << "[" << Check(ecuRegister, diagnostics::FLAG_OVERHEAT) << "] OVERHEAT" << '\n';
    std::cout << "[" << Check(ecuRegister, diagnostics::FLAG_LIMP_MODE) << "] LIMP MODE" << '\n';
    std::cout << "[" << Check(ecuRegister, diagnostics::FLAG_ABS_FAULT) << "] ABS FAULT" << '\n';
    std::cout << '\n';
}