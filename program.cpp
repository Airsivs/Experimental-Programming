#include "powertrain.h"
#include <iostream>
#include <cstdlib> 
#include <thread>
#include <chrono>

int getGearChoice() {
    std::cout << "---- VEKTORWERK DISTANZ UND TELEMETRIE KALKULATOR ----\n";
    std::cout << "-- GEAR SELECTION --\n";
    std::cout << "Select gear (1-6): ";
    int gear{};
    std::cin >> gear;
    return gear;
}

double getCarWeight() {
    std::cout << "---- VEKTORWERK DISTANZ UND TELEMETRIE KALKULATOR ----\n";
    std::cout << "-- FAHRZEUGGEWICHT --\n";
    std::cout << "Your car weight (kg): ";
    double weight{};
    std::cin >> weight;
    return weight;
}

double getCarSpeed() {
    std::cout << "---- VEKTORWERK DISTANZ UND TELEMETRIE KALKULATOR ----\n";
    std::cout << "-- GESCHWINDIGKEIT --\n";
    std::cout << "Your car speed (m/s): ";
    double speed{};
    std::cin >> speed;
    return speed;
}

double getMotorTorque() {
    std::cout << "---- VEKTORWERK DISTANZ UND TELEMETRIE KALKULATOR ----\n";
    std::cout << "-- MOTORDREHMOMENT --\n";
    std::cout << "Your engine torque (Nm): "; 
    double torque{};
    std::cin >> torque;
    return torque;
}

void statisticsShow(int gear, double gearRatio, double wTorque, double tForce, double dForce, double nForce, double accel) {
    std::cout << "=====================================================\n";
    std::cout << "      VEKTORWERK TELEMETRY & POWERTRAIN REPORT       \n";
    std::cout << "=====================================================\n";
    std::cout << " Selected Gear      : " << gear << " (Ratio: " << gearRatio << ")\n";
    std::cout << " Wheel Torque       : " << wTorque << " Nm\n";
    std::cout << " Tractive Force     : " << tForce << " N\n";
    std::cout << " Aerodynamic Drag   : " << dForce << " N\n";
    std::cout << " Net Acceleration   : " << nForce << " N\n";
    std::cout << " Instant Acceleration: " << accel << " m/s^2 (" << (accel / 9.81) << " G)\n";
    std::cout << "=====================================================\n";


}

int main() {
    
    int gear = getGearChoice();
    system("cls");

    double weight = getCarWeight();
    system("cls");

    double speed = getCarSpeed();
    system("cls");

    double torque = getMotorTorque();
    system("cls");

    double ratio  = calculateGearRatio(gear);
    double wTq    = calculateWheelTorque(torque, ratio);
    double tFr    = calculateTractiveForce(wTq);
    double dFr    = calculateDragForce(speed);
    double nFr    = calculateNetForce(tFr, dFr);
    double accel  = calculateAcceleration(nFr, weight);

    statisticsShow(gear, ratio, wTq, tFr, dFr, nFr, accel);

    std::this_thread::sleep_for(std::chrono::seconds(500));

    return 0;
}