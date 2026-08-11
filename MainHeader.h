#pragma once
#include <cstdint>
#include <string>
#include <algorithm>

constexpr std::uint8_t FLAG_ENGINE_ON { 0b0000'0001 };
constexpr std::uint8_t FLAG_ABS_ACTIVE { 0b0000'0010 };
constexpr std::uint8_t FLAG_TRACTION_CONTROL { 0b0000'0100 };
constexpr std::uint8_t FLAG_LOW_FUEL { 0b0000'1000 };
constexpr std::uint8_t FLAG_CHECK_ENGINE { 0b0001'0000 };
constexpr std::uint8_t FLAG_DOOR_OPEN { 0b0010'0000 };
constexpr std::uint8_t FLAG_SEATBELT_UNFASTENED { 0b0100'0000 };
constexpr std::uint8_t FLAG_CRITICAL_FAULT { 0b1000'0000 };

inline std::uint8_t vehicleState {0b0000'0000};

std::uint8_t Ignition(std::uint8_t& VehicularState);
void output(std::uint8_t VehicularState);;
std::int8_t hexConvert(std::uint8_t VehicularState);
std::uint8_t SeatbeltUnfastened(std::uint8_t& VehicularState);
std::uint8_t SeatbeltFastened(std::uint8_t& VehicularState);
std::uint8_t IceBrake(std::uint8_t& VehicularState);
std::uint8_t CriticalFault(std::uint8_t& VehicularState);
std::uint8_t ClearABStraction(std::uint8_t& VehicularState);