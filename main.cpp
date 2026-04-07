#include <iostream>
#include "include/calculator.h"
#include "include/utils.h"


int main() {
    const auto lang = "C++";
    std::cout << "Hello and welcome to " << lang << "!\n";
    std::cout << "Calculator add :" << Calculator::add(1, 3) << std::endl;
    logMessage("hello utils");
    return 0;
}
