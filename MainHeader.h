#pragma once
#include <cstdint>
#include <string>
#include <algorithm>

namespace flag{
    inline constexpr std::uint8_t COOLANT_TEMP {0b0000'0001};
    inline constexpr std::uint8_t STEERING_ANGLE {0b0000'0010};
    inline constexpr std::uint8_t BRAKE_CHECK {0b0000'0100};
    inline constexpr std::uint8_t LAUNCH_CTRL {0b0000'1000};
}

namespace data{

    inline std::uint8_t ECU_REGISTER {0b0000'0000};

    struct package{
        int RPM;
        double gearRatio;
        int gear;
        int targetspeed;
        double sensorspeed;
        std::string recommendation;
    };
    struct input{
        double coolantTemp;
        double steeringAngle;
        bool brakecheck;
        int tickAmount;
    };
}

data::package Drivetrain(data::package& data);
data::input InputFrame(data::input& input);
data::input FlagCheck(data::input& convert);
void OutputFrame(data::package& data, int tick, data::input& input);
static int tick{0};
void EndStatistics(int tick);


