#include "powertrain.h"
#include <cmath>

double calculateGearRatio(int gear) {
    switch (gear) {
        case 1: return 4.23;
        case 2: return 2.52;
        case 3: return 1.66;
        case 4: return 1.22;
        case 5: return 1.00;
        case 6: return 0.80;
        default: return 0.0; 
    }
}

double calculateWheelTorque(double motorTorque, double gearRatio) {
    constexpr double finalDriveRatio{3.45};
    constexpr double drivetrainEfficiency{0.85};
    return motorTorque * gearRatio * finalDriveRatio * drivetrainEfficiency;
}

double calculateTractiveForce(double wheelTorque) {
    constexpr double tireRadius{0.32}; 
    return wheelTorque / tireRadius;
}

double calculateDragForce(double carSpeed) {
    constexpr double dragCoefficient{0.30};
    constexpr double airDensity{1.225};
    constexpr double area{2.2};
    return 0.5 * airDensity * (carSpeed * carSpeed) * dragCoefficient * area;
}

double calculateNetForce(double tractiveForce, double dragForce) {
    return tractiveForce - dragForce;
}

double calculateAcceleration(double netForce, double carWeight) {
    if (carWeight <= 0.0) return 0.0; // Protection against division by zero
    return netForce / carWeight;
}