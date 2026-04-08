#include <iostream>
#include "include/calculator.h"
#include "include/utils.h"
#include "include/data_type.h"
#include "include/template.h"

void dataType() {
    DataType::demoIntegerOverflow();
    DataType::demoFloatingPrecision();
    DataType::demoTypeConversion();
    DataType::demoSizeAndLimits();
    DataType::demoBitOperations();
}

void templateDemo() {
    // 模版
    std::cout << "模版调用add(1,2): " << add(1, 2) << std::endl;
    std::cout << "模版调用add(1.1,2.2): " << add(1.1, 2.2) << std::endl;

    Container<int> c1;
    for (int i = 0; i < 100; i++) {
        c1.append(i);
    }
    std::cout << "模版调用c1.getItem(0): " << c1.getItem(0) << ", size: " << c1.getSize() << std::endl;
}

int main() {
    dataType();
    templateDemo();
    return 0;
}
