#pragma once

struct Vector3 {
    double x{};
    double y{};
    double z{};
};

double calculateGearRatio(int gear);
double calculateWheelTorque(double motorTorque, double gearRatio);
double calculateTractiveForce(double wheelTorque);
double calculateDragForce(double carSpeed);
double calculateNetForce(double tractiveForce, double dragForce);
double calculateAcceleration(double netForce, double carWeight);