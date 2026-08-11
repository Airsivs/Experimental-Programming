#include "MainHeader.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdint>

int main(){
    Ignition(vehicleState);
    output(vehicleState);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    system("cls");
    SeatbeltUnfastened(vehicleState);
    output(vehicleState);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    system("cls");
    SeatbeltFastened(vehicleState);
    output(vehicleState);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    system("cls");
    IceBrake(vehicleState);
    output(vehicleState);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    system("cls");
    CriticalFault(vehicleState);
    output(vehicleState);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    system("cls");
    ClearABStraction(vehicleState);
    output(vehicleState);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    system("cls");
}
