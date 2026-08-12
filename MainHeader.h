#pragma once
#include <cstdint>
#include <string>
#include <algorithm>

namespace diagnostics {
    constexpr std::uint8_t FLAG_OVERHEAT {0b0000'0001};
    constexpr std::uint8_t FLAG_LAUNCH_READY {0b0000'0010};
    constexpr std::uint8_t FLAG_ABS_FAULT {0b0000'0100};
    constexpr std::uint8_t FLAG_LIMP_MODE {0b0000'1000};
}

inline std::uint8_t ecuRegister {0b0000'0000};

namespace drivetrain{
    std::uint8_t Block1(std::uint8_t& ecuRegister);
    std::uint8_t Block2(std::uint8_t& ecuRegister);
    std::uint8_t Block3(std::uint8_t& ecuRegister);
};

void outputStart(std::uint8_t ecuRegister);
void output(std::uint8_t ecuRegister, int blockNumber, std::string_view eventHappening);