#include "profiler.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdint>

struct TelemetryPacket {
    float x {0};
    float y {0};
    float z {0};
    int engineTemperature {70};
    double acceleration {0};
    double currentSpeed {0};
    double TelemetryPreviousSpeed {0};
};

struct InitializationPacket {
    float x {0};
    float y {0};
    float z {0};
    int engineTemperature {70};
    double acceleration {5.4};
    double currentSpeed {0};
    double TelemetryPreviousSpeed {0};
};

struct UserData {
    double acceleration;
    double previousSpeed;
};

UserData grabUserInfo(){
    double PreviousSpeedInput{};
    double accelerationInput{};

    std::cout << "---VEKTORWERK---" << '\n';
    std::cout << "Input the following data: " << '\n';
    std::cout << "Simulation starting speed (m/s): ";
    std::cin >> PreviousSpeedInput;
    std::cout << '\n' << "Acceleration per second: ";
    std::cin >> accelerationInput;

    return {accelerationInput, PreviousSpeedInput};
}

TelemetryPacket calculateData(const TelemetryPacket& prevTelemetry){
    TelemetryPacket nextTelemetry;

    nextTelemetry.z = prevTelemetry.z;
    nextTelemetry.y = prevTelemetry.y;
    nextTelemetry.engineTemperature = prevTelemetry.engineTemperature;
    nextTelemetry.acceleration = prevTelemetry.acceleration;

    nextTelemetry.TelemetryPreviousSpeed = prevTelemetry.currentSpeed;
    
    nextTelemetry.currentSpeed = nextTelemetry.TelemetryPreviousSpeed + nextTelemetry.acceleration;
    nextTelemetry.x = prevTelemetry.x + nextTelemetry.currentSpeed;
    
    return nextTelemetry;
}

void PrintSpeed(const TelemetryPacket& Print){
    std::cout << "PRINT SECTION" << '\n';
    std::cout << "X: " << Print.x << " m" << '\n'
              << "Y: " << Print.y << " m" << '\n'
              << "Z: " << Print.z << " m" << '\n'
              << "Temp: " << Print.engineTemperature << " C"<< '\n'
              << "Accel: " << Print.acceleration << " {M/S}" << '\n'
              << "Current Speed: " << Print.currentSpeed << " {M/S}" << '\n'
              << "Prev Speed: " << Print.TelemetryPreviousSpeed << " {M/S}" << "\n";
}

int main(){
    UserData userSettings = grabUserInfo();

    TelemetryPacket TP1;
    TP1.TelemetryPreviousSpeed = userSettings.previousSpeed;
    TP1.currentSpeed = userSettings.previousSpeed;
    TP1.acceleration = userSettings.acceleration;

    for (int i = 1; i < 5000; i++) {
        if (TP1.TelemetryPreviousSpeed < 100) {

            TP1 = calculateData(TP1); 
            
            std::cout << "\033[2J\033[1;1H"; 
            
            PrintSpeed(TP1);

            std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        } else {
            break; 
        }
    }

    return 0;
}
