#include <iostream>
#include "include/data_type.h"
#include "include/template.h"
using namespace std;

void applyDataTypeByDemo() {
    // 2. 综合应用
    cout << "\n========== 9. 综合应用：银行系统 ==========" << endl;
    BankAccount account(10086, 1, 3.5);  // 3.5%年利率
    account.display();

    cout << "\n模拟交易,存款 10000 元:" << endl;
    account.deposit(10000);
    cout << "当前余额: " << account.getBalance() << " 元" << endl;
    account.withdraw(2500);
    cout << "取款 2500 元" << endl;
    cout << "当前余额: " << account.getBalance() << " 元" << endl;

    account.addInterest();
    cout << "一年后余额: " << account.getBalance() << " 元" << endl;

    // 3. 类型选择总结
    cout << "\n========== 10. 学习要点总结 ==========" << endl;
    cout << R"(
        关键要点：
        1. 整型注意溢出，使用固定宽度类型保证可移植性
        2. 浮点数不能直接比较相等，需要判断差值
        3. 有符号与无符号混用会导致意外结果
        4. size_t 用于数组索引和循环计数器
        5. 位操作可以高效管理多个布尔标志
        6. char 既是字符也是小整数，注意符号性
        7. auto 简化类型声明，但不要过度使用
        8. 根据需求选择最小够用的类型以节省内存
    )";
    cout << "\nDemo 完成！" << endl;
}

void dataType() {
    DataType::demoIntegerOverflow();
    DataType::demoFloatingPrecision();
    DataType::demoTypeConversion();
    DataType::demoSizeAndLimits();
    DataType::demoBitOperations();
    DataType::demoCharAndStrings();
    DataType::demoTypeBestPractices();
    DataType::demoTypeDeduction();
    applyDataTypeByDemo();
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
    // templateDemo();
    return 0;
}
