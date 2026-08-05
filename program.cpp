#include "profiler.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdint>


void logDiagnosticEvent(std::string_view SubSystem, std::string_view OpName, std::int16_t CANtelemetryAddress, std::int16_t ReceivedBitmask, std::string_view vin){

        system("cls");

        std::cout << '\n' << "Vehicle operator name: " << OpName;
        std::cout << '\n' << "Vehicle VIN: " << vin;
        std::cout << '\n' << "Vehicle Subsystem: " <<  SubSystem;
        std::cout << '\n' << "Vehicle CAN telemetry address: " <<  std::hex << CANtelemetryAddress << std::dec << '\n';

        switch(ReceivedBitmask) {
        case 0b0001:
            std::cout << " Diagnostic bitmask status:  OVERHEATING" << '\n';
            std::cout << " Received bitmask code status:  " << ReceivedBitmask << '\n';    
            break;
        case 0b0010:
            std::cout << " Diagnostic bitmask status:  LOW VOLTAGE" << '\n';
            std::cout << " Received bitmask code status:  " << ReceivedBitmask << '\n';
            break;
        case 0b0011:
            std::cout << " Diagnostic bitmask status:  OVERHEATING & LOW VOLTAGE" << '\n';
            std::cout << " Received bitmask code status:  " << ReceivedBitmask << '\n'; 
            break;
        case 0b0100:
            std::cout << " Diagnostic bitmask status:  SENSOR DISCONNECTED" << '\n';
            std::cout << " Received bitmask code status: " << ReceivedBitmask << '\n';
            break;
        case 0b0110:
            std::cout << " Diagnostic bitmask status:  SENSOR DISCONNECTED & LOW VOLTAGE" << '\n';
            std::cout << " Received bitmask code status:  " << ReceivedBitmask << '\n'; 
            break;
        case 0b0111:
            std::cout << " Diagnostic bitmask status:  OVERHEATING, LOW VOLTAGE & SENSOR DISCONNECTED" << '\n';
            std::cout << " Received bitmask code status:  " << ReceivedBitmask << '\n'; 
            break;
        case 0b1000:
            std::cout << " Diagnostic bitmask status:  STORAGE FULL" << '\n';
            std::cout << " Received bitmask code status:  " << ReceivedBitmask << '\n';
            break;
        case 0b1100:
            std::cout << " Diagnostic bitmask status:  SENSOR DISCONNECTED & STORAGE FULL" << '\n';
            std::cout << " Received bitmask code status:  " << ReceivedBitmask << '\n'; 
            break;
        case 0b1110:
            std::cout << " Diagnostic bitmask status:  SENSOR DISCONNECTED, STORAGE FULL & LOW VOLTAGE" << '\n';
            std::cout << " Received bitmask code status:  " << ReceivedBitmask << '\n'; 
            break;
        case 0b1111:
            std::cout << " Diagnostic bitmask status:  OVERHEATING, SENSOR DISCONNECTED, STORAGE FULL & LOW VOLTAGE" << '\n';
            std::cout << " Received bitmask code status:  " << ReceivedBitmask << '\n'; 
            break;
        default:
            std::cout << " Diagnostic bitmask status:  NO ERROR DETECTED" << '\n';
            std::cout << " Received bitmask code status:  " << ReceivedBitmask << '\n';
            break;
    }
};


int main(){
    
    std::string operatorName {};
    std::string VIN {};
    std::int16_t CANtelemetryAddress {0x111};

    int sybsystemID {0x4F2A};
    std::int16_t bitmask {0b1000};

    constexpr std::string_view powertrain {"POWERTRAIN_ECU"};
    constexpr std::string_view abs_module {"ABS_MODULE"};
    constexpr std::string_view telemetry_unit {"TELEMETRY_UNIT"};

    // Create a temporary C-style string and assign those variables to view those
    // then we pass that onto the function

    // std::string is expensive to initialize therefor I replaced it with C-style

    std::cout << "VEKTORWERK CAN-BUS DIAGNOSTIC TELEMETRY LOGGER" << '\n';
    std::cout << "Input your name: ";
    std::getline(std::cin >> std::ws, operatorName);
    std::cout << '\n' << "Input your Vehicle Identification Tag: ";
    std::getline (std::cin >> std::ws, VIN);

    logDiagnosticEvent(powertrain,operatorName,CANtelemetryAddress,bitmask,VIN);


    return 0;
}
