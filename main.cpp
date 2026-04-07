#include <iostream>
#include "include/calculator.h"
#include "include/utils.h"
#include "include/data_type.h"


int main() {
    const auto lang = "C++";
    std::cout << "Hello and welcome to " << lang << "!\n";
    std::cout << "Calculator add :" << Calculator::add(1, 3) << std::endl;
    logMessage("hello utils");
    DataType::demoIntegerOverflow();
    return 0;
}
