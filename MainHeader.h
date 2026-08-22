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
        double vehicleHealth; // idea; have a chance depending on vehicle health to have a critical failure during run - implement whenever i feel like it. have it be inputted in the input frame with the rest of general-vehicle configs
    };

    struct drivetrainModel{
        int gain1;
        int gain2;
        int gain3;
        int gain4;
        int gain5;
        double gearRatio1;
        double gearRatio2;
        double gearRatio3;
        double gearRatio4;
        double gearRatio5;
        double finadriveRatio;
        double tireCircumference;
        bool turbo;
        int turboAmount;
        int modelID;
    };
}

data::package Drivetrain(data::package& data);
data::input InputFrame(data::input& input);
data::input FlagCheck(data::input& convert, data::drivetrainModel& drive, std::string_view VehicleName);
void OutputFrame(data::package& data, int tick, data::input& input, std::string_view projectVer);
int drivetrainInputFrame();
data::drivetrainModel ModelSelectionCheck(int selected,data::drivetrainModel& drive);
std::string modelName(data::drivetrainModel drive);
static int tick{0};
void EndStatistics(int tick);


