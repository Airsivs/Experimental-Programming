#include "MainHeader.h"
#include <iostream>
#include <cstdint>
#include <string_view> 
#include <thread>
#include <bitset>
#include <chrono>

namespace {

    char CheckSport(std::uint8_t modeRegister){
        using std::cout;
        if (flag::MODE_SPORT & modeRegister){
            return 'X';
        }
        else{
            return ' ';
        }
    };

    char CheckEco(std::uint8_t modeRegister){
        using std::cout;
        if (flag::MODE_ECO & modeRegister){
            return 'X';
        }
        else{
            return ' ';
        }
    };

    char CheckTrack(std::uint8_t modeRegister){
        using std::cout;
        if (flag::MODE_TRACK & modeRegister){
            return 'X';
        }
        else{
            return ' ';
        }
    };
    
    char CheckLaunch(std::uint8_t modeRegister){
        using std::cout;
        if (flag::MODE_LAUNCH_CTRL & modeRegister){
            return 'X';
        }
        else{
            return ' ';
        }
    };
    

}

std::uint8_t Frame2BitManip(std::uint8_t& modeRegister){
    modeRegister |= flag::MODE_SPORT;
    modeRegister &= ~flag::MODE_ECO;
    return flag::MODE_SPORT | flag::MODE_ECO;
};

std::uint8_t Frame3BitManip(std::uint8_t& modeRegister){
    modeRegister |= flag::MODE_TRACK;
    return flag::MODE_TRACK;
};

std::uint8_t Frame5BitManip(std::uint8_t& modeRegister){
    modeRegister &= ~(flag::MODE_ECO | flag::MODE_LAUNCH_CTRL | flag::MODE_SPORT | flag::MODE_TRACK);
    return flag::MODE_ECO | flag::MODE_LAUNCH_CTRL | flag::MODE_SPORT | flag::MODE_TRACK;
};


void FormatPayload(std::uint8_t modeRegister){
    std::cout << "ACTIVE MODES: [" << CheckEco(modeRegister) << "] ECO | [" << CheckSport(modeRegister) << "] SPORT | [" << CheckTrack(modeRegister) << "] TRACK | [" << CheckLaunch(modeRegister) << "] LAUNCH CTRL" << '\n';
};




