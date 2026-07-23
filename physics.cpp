#include <iostream>
#include <chrono>
#include <thread>

double Calculation(double Velocity, double DragCOEFFICIENT, double Area){
    double airDensity{1.225};
    double force{};

    double airdensityhalf = airDensity/2;
    double velocitydouble = Velocity*Velocity;
    double CDA = DragCOEFFICIENT*Area;
    force = airdensityhalf*velocitydouble*CDA;
    
    return force;
};
