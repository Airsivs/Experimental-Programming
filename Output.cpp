#include "MainHeader.h"
#include <iostream>
#include <cstdint>
#include <string_view> 
#include <thread>
#include <bitset>
#include <chrono>

std::int8_t hexConvert(std::uint8_t VehicularState12){
    static_cast<int>(VehicularState12);
    return VehicularState12;
};

std::string Check(std::uint8_t VehicularState, std::uint8_t InputFlag){
    return (VehicularState & InputFlag) ? "X" : " ";
}

void output(std::uint8_t VehicularState){
    std::cout << "=====================================================" << '\n';
    std::cout << "VEKTORWERK ECU DIAGNOSTIC - EVENT: IGNITION START" << '\n';
    std::cout << "=====================================================" << '\n';

    std::cout << "RAW MEMORY REGISTER:" << '\n';
    std::cout << "  Binary: " << std::bitset<8>(VehicularState) << '\n';
    std::cout << "  Hex: 0x" << std::hex << static_cast<int>(VehicularState) << '\n';
    std::cout << "  Decimal: " << std::dec << static_cast<int>(VehicularState) << '\n';

    std::cout << "ACTIVE SYSTEMS: " << '\n';
    std::cout << "[" << Check(VehicularState, FLAG_ENGINE_ON) << "] ENGINE ON" << '\n';
    std::cout << "[" << Check(VehicularState, FLAG_ABS_ACTIVE) << "] ABS ACTIVE" << '\n';
    std::cout << "[" << Check(VehicularState, FLAG_TRACTION_CONTROL) << "] TRACTION CONTROL" << '\n';
    std::cout << "[" << Check(VehicularState, FLAG_CHECK_ENGINE) << "] CHECK ENGINE" << '\n';
    std::cout << "[" << Check(VehicularState, FLAG_LOW_FUEL) << "] LOW FUEL" << '\n';
    std::cout << "[" << Check(VehicularState, FLAG_DOOR_OPEN) << "] DOOR OPEN" << '\n';
    std::cout << "[" << Check(VehicularState, FLAG_SEATBELT_UNFASTENED) << "] SEATBELT UNFASTENED" << '\n';
    std::cout << "[" << Check(VehicularState, FLAG_CRITICAL_FAULT) << "] CRITICAL FAULT" << '\n';


}
