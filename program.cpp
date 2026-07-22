#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>

void EngineDisplacement(){
    int cylinders{};
    double bore{};
    double stroke{};
    double volume{};
    double radius{};
    std::cout << "Welcome to the engine displacement mode!" << '\n';
    std::cout << "Everything should be written in milimeters." << '\n';
    std::cout << "We require the following info:" << '\n';
    std::cout << "Amount of cylinders: ";
    std::cin >> cylinders;
    std::cout << '\n' << "Dimensions of the bore: ";
    std::cin >> bore;
    std::cout << '\n' << "Dimensions of the stroke: ";
    std::cin >> stroke;

    system("cls");
    radius = bore / 2.0;
    double singleCylinderVolume = 3.1415926535 * (radius * radius) * stroke;
    volume = (singleCylinderVolume * cylinders) / 1000.0;
    std::cout << "Calculating..." << '\n';
    std::this_thread::sleep_for(std::chrono::seconds(2));
    system("cls");
    std::cout << "The displacemet of your engine is: " << volume;
    std::this_thread::sleep_for(std::chrono::seconds(2));
};

void LinearEstimator(){
    double gforce {};
    double seconds{};
    
    std::cout << "Welcome to the Linear G-Force Estimator mode!" << '\n';
    std::cout << "We require the following info:" << '\n';
    std::cout << "in how many seconds does the vehicle reach 100km/h? " << '\n';
    std::cin >> seconds;
    system("cls");
    double top = (100/3.6)*seconds;
    gforce = top/9.81;
    std::cout << "Performing calculation";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    system("cls");
    std::cout << "G-Force: " << gforce;
    std::this_thread::sleep_for(std::chrono::seconds(5));
};

void fuelBurnRate(){
    double fuel_needed{};
    double speed{};
    double consumption{};
    double distance{};
    
    std::cout << "Welcome to the Fuel Burn Rate mode!" << '\n';
    std::cout << "This mode calculates the amount of fuel needed for a trip" << '\n';
    std::cout << "We require the following info:" << '\n';
    std::cout << "What is the average speed of the trip? (km/h)" << '\n';
    std::cin >> speed;
    std::cout << "What is the distance of the trip? (km)" << '\n';
    std::cin >> distance;
    std::cout << "What is the consumption rate of your selected vehicle? (avg 6L/100km)" << '\n';
    std::cin >> consumption;

    system("cls");
    fuel_needed = (distance/speed)*consumption;
    std::cout << "Calculation output: " << '\n';
    std::cout << "Distance: " << distance << " KM" <<  '\n';
    std::cout << "Speed: " << speed << " KM/H" << '\n';
    std::cout << "Fuel required: " << fuel_needed << " Liters" << '\n';
    std::this_thread::sleep_for(std::chrono::seconds(5));


};

void clearScreen() {
    system("cls");
}

int main(){
    int input{};
    std::cout << "---------VEKTORWERK INTERNAL SOFTWARE---------" << '\n';
    std::cout << "Welcome employee, to select a mode please press the number corresponding to the mode:" << '\n';
    std::cout << "Engine Displacement Calculator - 1" << '\n';
    std::cout << "Linear G-Force Estimator - 2" << '\n';
    std::cout << "Fuel Burn Rate - 3" << '\n';
    std::cout << "Input selection: ";
    std::cin >> input;

    switch (input) {
        case 1:
            clearScreen();
            EngineDisplacement();
            break;
        case 2:
            clearScreen();
            LinearEstimator();
            break;
        case 3:
            clearScreen();
            fuelBurnRate();
            break;
        default:
            std::cout << '\n' << "Invalid selection";
            std::this_thread::sleep_for(std::chrono::seconds(2));
            break;
    };      
    return 0;
};