#pragma once
#include <cstdint>
namespace vektorwerk {

        struct Vector3{
            double x;
            double y;
            double z;
        };

    void RPMcheck(std::uint16_t InputRPM);
    void startInterface();
}