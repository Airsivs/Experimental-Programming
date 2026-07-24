#include "profiler.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdint>

int main(){
    vektorwerk::startInterface();
    vektorwerk::RPMcheck(4500);
    vektorwerk::RPMcheck(8200);

    return 0;

}