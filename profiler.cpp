#include "profiler.h"
#include <iostream>
#include <cstdint>
namespace vektorwerk{


    void RPMcheck(std::uint16_t InputRPM){
        std::uint16_t Limit{7500};
        if (InputRPM > Limit){
            std::cout << "[TELEMETRY WARNING] REDLINE EXCEEDED" << '\n';
        }
        else{
            std::cout << "[TELEMETRY] RPM OPTIMAL" << '\n';
        }

    };

    void startInterface(){
        std::cout << "------Vektorwerk RPM Architecture test------" << '\n';
    };


}