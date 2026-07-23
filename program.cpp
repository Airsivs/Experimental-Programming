#include <iostream>
#include <chrono>
#include <thread>

double Calculation(double Velocity, double DragCOEFFICIENT, double Area);


int main(){
    double inputVelocity{};
    double inputCd{};
    double inputArea{};

    std::cout << "---VEKTORWERK AERODYNAMICS SIM---" << '\n';
    std::cout << "Input following variables;"<< '\n';
    std::cout << "Velocity of the car (m/s): ";
    std::cin >> inputVelocity;
    std::cout << '\n';
    std::cout << "Drag coefficient (moder sedan - 0.30): ";
    std::cin >> inputCd;
    std::cout << '\n';
    std::cout << "Frontal area of the car in square meters(e.g., 2.2m^2): ";
    std::cin >> inputArea;
    std::cout << '\n';

    double FinalDragForce = Calculation(inputVelocity,inputCd,inputArea);
    system("cls");
    std::cout << "Estimated drag force: " << FinalDragForce;

    std::this_thread::sleep_for(std::chrono::seconds(2));

    return 0;
}