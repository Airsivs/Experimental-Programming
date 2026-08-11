#include "MainHeader.h"
#include <iostream>
#include <cstdint>
#include <string_view> 
#include <thread>
#include <bitset>
#include <chrono>

std::uint8_t Ignition(std::uint8_t& VehicularState){
    VehicularState |= (FLAG_ENGINE_ON);
    return FLAG_ENGINE_ON;
}

std::uint8_t SeatbeltUnfastened(std::uint8_t& VehicularState){
    VehicularState |= (FLAG_SEATBELT_UNFASTENED);
    return FLAG_SEATBELT_UNFASTENED;
}

std::uint8_t SeatbeltFastened(std::uint8_t& VehicularState){
    VehicularState &= ~FLAG_SEATBELT_UNFASTENED;
    return FLAG_SEATBELT_UNFASTENED;
}

std::uint8_t IceBrake(std::uint8_t& VehicularState){
    VehicularState |= (FLAG_ABS_ACTIVE | FLAG_TRACTION_CONTROL);
    return FLAG_ABS_ACTIVE | FLAG_TRACTION_CONTROL;
}

std::uint8_t CriticalFault(std::uint8_t& VehicularState){
    VehicularState |= (FLAG_CRITICAL_FAULT | FLAG_CHECK_ENGINE);
    return FLAG_CRITICAL_FAULT | FLAG_CHECK_ENGINE;
}

std::uint8_t ClearABStraction(std::uint8_t& VehicularState){
    VehicularState &= ~(FLAG_ABS_ACTIVE | FLAG_TRACTION_CONTROL);
    return FLAG_ABS_ACTIVE | FLAG_TRACTION_CONTROL;
}

