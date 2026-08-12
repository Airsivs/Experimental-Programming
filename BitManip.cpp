#include "MainHeader.h"
#include <iostream>
#include <cstdint>
#include <string_view> 
#include <thread>
#include <bitset>
#include <chrono>

namespace drivetrain{

    std::uint8_t Block1(std::uint8_t& ecuRegister){
        ecuRegister |= diagnostics::FLAG_LAUNCH_READY;
        return diagnostics::FLAG_LAUNCH_READY;
    };

    std::uint8_t Block2(std::uint8_t& ecuRegister){
        ecuRegister &= ~diagnostics::FLAG_LAUNCH_READY;
        ecuRegister |= (diagnostics::FLAG_ABS_FAULT | diagnostics::FLAG_LIMP_MODE | diagnostics::FLAG_OVERHEAT);
        return diagnostics::FLAG_LAUNCH_READY | diagnostics::FLAG_LIMP_MODE | diagnostics::FLAG_OVERHEAT | diagnostics::FLAG_ABS_FAULT;
    };

    std::uint8_t Block3(std::uint8_t& ecuRegister){
        ecuRegister &= ~(diagnostics::FLAG_LAUNCH_READY | diagnostics::FLAG_ABS_FAULT | diagnostics::FLAG_LIMP_MODE | diagnostics::FLAG_OVERHEAT);
        return diagnostics::FLAG_LAUNCH_READY | diagnostics::FLAG_LIMP_MODE | diagnostics::FLAG_OVERHEAT | diagnostics::FLAG_ABS_FAULT;
    };
};

