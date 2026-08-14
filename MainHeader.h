#pragma once
#include <cstdint>
#include <string>
#include <algorithm>

namespace flag{
    inline constexpr std::uint8_t MODE_ECO {0b0000'0001};
    inline constexpr std::uint8_t MODE_SPORT {0b0000'0010};
    inline constexpr std::uint8_t MODE_TRACK {0b0000'0100};
    inline constexpr std::uint8_t MODE_LAUNCH_CTRL {0b0000'1000};
}

inline std::uint8_t modeRegister {0b0000'0001};
std::string ReturnModes(std::uint8_t modeRegister);
void FormatPayload(std::uint8_t modeRegister);
void logFrame(std::uint8_t modeRegister);
std::uint8_t Frame2BitManip(std::uint8_t& modeRegister);
std::uint8_t Frame3BitManip(std::uint8_t& modeRegister);
std::uint8_t Frame5BitManip(std::uint8_t& modeRegister);
void Initialize();
void EndTelemetry();