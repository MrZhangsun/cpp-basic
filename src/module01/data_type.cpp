//
// Created by 大江流韵 on 2026/4/7.
//
#include <iostream>
#include <iomanip> // input-output manipulators（输入输出格式控制工具）
#include <limits>
#include <locale>
#include "../../include/data_type.h"

using namespace std;

// :: 是 作用域解析运算符（scope resolution operator）≈ “在某个命名空间/类里面找”
// 类型：size_t
// 含义：无符号整数类型
// 常用于表示：
// 内存大小
// 数组长度
// 类型字节数
static void printTypeInfo(const char* name, size_t size, const char* range) {
    // cout << left: 表示后面的输出按左对齐, 默认是右对齐
    // setw(15): 表示：输出占15个字符宽度
    cout << left << setw(10) << name
    << "大小：" << setw(2) << size <<"字节, "
    << "范围：" << range << endl;
}
// 演示整型溢出
void DataType::demoIntegerOverflow() {
    cout << "\n========== 1. 整型溢出演示 ==========" << endl;
    /* numeric_limits<data_type>: 模板类, 定义在：limits.h中，用于获取某种数据类型的“极限值信息”
     * ::max() 是它的静态方法
    */
    constexpr unsigned int max_uint = numeric_limits<unsigned int>::max();
    cout << "unsigned int 最大值：" << max_uint << endl;
    cout << "最大值+1：" << max_uint + 1 << " (回绕到0)" << endl;

    constexpr int max_int = numeric_limits<int>::max();
    cout << "int 最大值：" << max_int << endl;
    cout << "int最大值+1：" << max_int + 1 << "回到最小的负数：-2147483648" << endl;

    constexpr int min_int = numeric_limits<int>::min();
    cout << "int 最小值：" << min_int << endl;
    cout << "int最小值-1：" << min_int - 1 << "回到最大的正数：2147483647" << endl;
}

void DataType::demoFloatingPrecision() {
    cout << "\n========== 2. 浮点数精度问题 ==========" << endl;
    float f = 0.0f;
    for (int i = 0; i < 10; i++) {
        f += 0.1f;
    }

    cout << "0.1 累加10次 (float): " << setprecision(15) << f << endl;
    cout << "期望值: 1.0" << endl;
    cout << "误差: " << f - 1.0 << endl;

    double d = 0.0f;
    for (int i = 0; i < 10; i++) {
        d += 0.1f;
    }
    cout << "0.1 累加10次 (double): " << setprecision(15) << d << endl;
    cout << "double精度更高，但仍有误差: " << d - 1.0 << endl;

    // 浮点数比较陷阱
    cout << "\n浮点数比较陷阱:" << endl;
    constexpr float a = 0.1f;
    constexpr float b = 0.2f;
    constexpr float c = a + b;
    cout << "0.1 + 0.2 = " << setprecision(17) << c << endl;
    cout << "是否等于0.3？" << (c == 0.3f ? "相等" : "不相等") << endl;
    cout << "正确比较方法：" << (abs(c - 0.3f) < 1e-6 ? "相等" : "不相等") << endl;
}

void DataType::demoTypeConversion() {
    cout << "\n========== 3. 类型转换 ==========" << endl;
    // 隐式转换（可能丢失数据）
    constexpr int i = 1000;
    constexpr short s = i;  // 隐式转换，可能溢出
    cout << "int 1000 转 short: " << s << endl;

    /*
     * 1000000 (十进制) = 1111 0100 0010 0100 0000 (二进制)
     * 转成short 16位，只保留低位：0100 0010 0100 0000
     * 对应的十进制是：16960，发生了截断/溢出
     * 这种操作在C++中是合法，但危险
     * 大整数转 short 时：
👉   * 只保留低 16 位 = 对 2¹⁶ 取模
     */
    constexpr int big = 1000000;
    constexpr short small = big;
    cout << "int " << big << " 转 short: " << small << " (溢出!)" << endl;

    // 显式转换
    constexpr double pi = 3.14159265359;
    constexpr int int_pi = static_cast<int>(pi);  // 截断小数
    cout << "double " << pi << " 转 int: " << int_pi << endl;

    // 有符号与无符号转换
    // si 会被转换成 unsigned int！类型不一致，不要直接进行比较，转成统一的类型后进行比较
    constexpr unsigned int u = 10;
    constexpr int si = -5;
    cout << "无符号表陷阱：" << u << ">" << si << endl;
    cout << ((u > si) ? "true" : "false") << endl;
    cout << "实际: -5 被转换为无符号整数 " << static_cast<unsigned int>(si) << endl;

    // 算术转换
    cout << "\n算术转换示例:" << endl;
    cout << "10 / 3 = " << 10 / 3 << " (整数除法，截断)" << endl;
    cout << "10.0 / 3 = " << 10.0 / 3 << " (浮点除法)" << endl;
    cout << "10 / 3.0 = " << 10 / 3.0 << " (自动提升为浮点)" << endl;
}

/**
 * 演示sizeof和类型特性
 */
void DataType::demoSizeAndLimits() {
    cout << "\n========== 4. 各类型大小和范围 ==========" << endl;
    cout << left;
    // sizeof 的结果单位是：字节（byte）
    // 整型
    printTypeInfo("bool", sizeof(bool), "true/false");
    printTypeInfo("char", sizeof(char), "-128 to 127 (signed) or 0-255");
    printTypeInfo("short", sizeof(short), "-32,768 to 32,767");
    printTypeInfo("int", sizeof(int), "-2,147,483,648 to 2,147,483,647");
    /*
     * 由于long的长度在不同操作系统上，长度不一致，因此，对于长度敏感的操作，请使用int64_t，int32_t...这种固定宽度数据类型。
     * Windows:   long = 4 字节
     * Linux/mac: long = 8 字节
     */
    printTypeInfo("long", sizeof(long), "-2^31 to 2^31-1 (通常)");
    printTypeInfo("long long", sizeof(long long), "-9.22e18 to 9.22e18");

    // 无符号整型
    printTypeInfo("unsigned int", sizeof(unsigned int), "0 to 4,294,967,295");
    printTypeInfo("size_t", sizeof(size_t), "平台相关的无符号整型");

    // 浮点型
    printTypeInfo("float", sizeof(float), "-128 to 127.0");
    printTypeInfo("double", sizeof(double), "-128 to 127.0");
    printTypeInfo("long double", sizeof(long double), "-128 to 127.0");

    // 固定宽度类型
    cout << "\n固定宽度类型 (C++11):" << endl;
    printTypeInfo("int8_t", sizeof(int8_t), "-128 to 127");
    printTypeInfo("int16_t", sizeof(int16_t), "-32,768 to 32,767");
    printTypeInfo("int32_t", sizeof(int32_t), "-2^31 to 2^31-1");
    printTypeInfo("int64_t", sizeof(int64_t), "-2^63 to 2^63-1");
}

// 演示位操作
void DataType::demoBitOperations() {
    cout << "\n========== 5. 位操作演示 ==========" << endl;
    unsigned char flags = 0b00000000;  // 二进制字面量 (C++14)
    // 定义标志位
    constexpr unsigned char READ_BIT   = 0b00000001;  // 位0
    constexpr unsigned char WRITE_BIT  = 0b00000010;  // 位1
    constexpr unsigned char EXEC_BIT   = 0b00000100;  // 位2

    cout << "初始值: " << bitset<8>(flags) << " (0)" << endl;

    flags |= READ_BIT;
    cout << "初始值：" << bitset<8>(flags) << " (0)" << endl;

    flags |= WRITE_BIT;
    cout << "设置写权限：" << bitset<8>(flags) << endl;

    // 检查位
    cout << "有读权限? " << (flags & READ_BIT ? "是" : "否") << endl;
    cout << "有写权限? " << (flags & WRITE_BIT ? "是" : "否") << endl;
    cout << "有执行权限? " << (flags & EXEC_BIT ? "是" : "否") << endl;

    // 清除写权限
    flags &= ~WRITE_BIT; // 0b00000010 -> ~0b00000010 > 0b11111101 & 00000011 = 0b00000001
    // 清除读权限
    flags &= ~READ_BIT; // 0b00000001 > ~0b00000001 > 0b11111110 & 0b00000001 = 0b00000000

    // 切换位
    flags |= EXEC_BIT;
    flags ^= EXEC_BIT;
    cout << "切换执行权限: " << bitset<8>(flags) << endl;

    // 移位操作
    constexpr unsigned int value = 0b00000001;
    cout << "\n移位操作:" << endl;
    cout << "1 << 3 = " << (value << 3) << " (二进制: "
         << bitset<8>(value << 3) << ")" << endl;
    cout << "16 >> 2 = " << (16 >> 2) << " (二进制: "
         << bitset<8>(16 >> 2) << ")" << endl;
}

// 演示char和字符串处理
void DataType::demoCharAndStrings() {
    cout << "\n========== 6. 字符类型详解 ==========" << endl;

    // char 类型
    constexpr char c = 'A';
    cout << "char '" << c << "'的ASCII码：" << static_cast<int>(c) << endl;

    // char 作为整数使用
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        cout << ch << " ";
    }
    cout << endl;

    // 转义字符
    cout << "转义字符：\n\t\"Hello\"\n\t\"World\"\n\\n" << endl;

    // 宽字符（占用多个字节的字符）
    std::locale::global(std::locale(""));
    std::wcout.imbue(std::locale());

    constexpr wchar_t wc = L'中';
    wcout << L"宽字符: " << wc << L"(代码点: " << static_cast<int>(wc) << L")" << endl;

    // char16_t 和 char32_t
    char16_t c16 = u'中';
    char32_t c32 = U'中';
    cout << "char16_t大小：" << sizeof(char16_t) << " 字节" << endl;
    cout << "char32_t大小：" << sizeof(char32_t) << " 字节" << endl;

    // 字符串字面量
    constexpr char* str = "Hello, World!";
    constexpr wchar_t* wstr = L"你好，世界";
    // auto 的作用是：
    // 👉 让编译器自动推导变量类型，避免手写复杂类型
    constexpr auto u16str = u"你好，世界";
    const char32_t* u32str = U"Hello UTF-32";
    cout << "UTF-8字符串: " << str << endl;
}

// 实际应用：类型选择的最佳实践
void DataType::demoTypeBestPractices() {
    cout << "\n========== 7. 类型选择最佳实践 ==========" << endl;
    // 1. 循环计数器 - 使用size_t
    int arr[] = {1, 2, 3, 4, 5};
    // size_t 是一个无符号整型，用来表示大小，位置，索引等等。
    for (size_t i = 0; i < std::size(arr); i++) {
        cout << "the " << i << "个元素：" << arr[i] << " ";
    }
    cout << endl;

    // 2. 精确大小的需求 - 使用固定宽度类型
    cout << "2. 网络协议/文件格式: ";
    constexpr uint32_t package_id = 0x12345678;
    constexpr uint16_t package_length = 0x1234;
    cout << "包ID: " << hex << package_id << ", 包长度: " << dec << package_length << endl;

    // 3. 布尔标志 - 使用bool
    constexpr bool is_valid = true;
    constexpr bool is_processed = false;
    cout << "3. 布尔标志: " << boolalpha << is_valid << "/ " <<is_processed << noboolalpha << endl;

    // 4. 大量浮点运算 - double精度足够
    const double* large_array = new double[1000000]; // 分配在堆内存中
    cout << "4. 科学计算：double数组1000000个元素" << endl;
    delete[] large_array;

    // 5. 节省内存 - 使用最小够用的类型
    struct SmallStruct {
        uint8_t age;        // 0-255足够
        uint16_t score;     // 0-65535足够
        bool passed;        // 布尔值
    };

    SmallStruct small_struct = {18, 90, true};
    cout << "5. 内存优化：SmallStruct大小=" << sizeof(SmallStruct) << "字节, 实例化对象大小：" << sizeof(small_struct) << endl;
}

// 高级：类型推导和auto
void DataType::demoTypeDeduction() {
    cout << "\n========== 8. 类型推导 ==========" << endl;
    auto x = 10;
    auto y = 3.14;
    auto z = 3.14f;
    auto b = true;
    auto c = 'a';

    cout << "auto x = 10; x的类型是：" << typeid(x).name() << endl;
    cout << "auto y = 3.14; y的类型是：" << typeid(y).name() << endl;
    cout << "auto z = 3.14f; z的类型是：" << typeid(z).name() << endl;
    cout << "auto b = true; b的类型是：" << typeid(b).name() << endl;
    cout << "auto c = 'a'; c的类型是：" << typeid(c).name() << endl;

    /*
     * decltype 的作用是：获取一个表达式的“精确类型”（包括引用和 const）
     * 和 auto 的本质区别（核心）：
     * auto会：
     *   去掉 const
     *   去掉引用
     */
    constexpr int value = 42;
    /*
     * 指针和引用的区别：
     * 指针：存储的是内存地址，是一个变量，占用内存，可以为空，可以改变值（指向不同的内存地址）；
     * 引用：是变量的别名，不是变量，不占内存，必须初始化；
     */
    const int& ref = value; // 创建了变量value的一个别名，引用
    decltype(ref) result = value; // 获取变量value的精确类型， decltype(ref) = const int&, 作为result的类型
    cout << "decltype推导：" << typeid(result).name() << endl;

    // auto 和 const
    constexpr int const_val = 100;
    auto val1 = const_val; // int (去掉const)
    const auto val2 = const_val; // const int
    auto& val3 = const_val; // const int&
    cout << "val1: " << typeid(val1).name() << endl;
    cout << "val2: " << typeid(val2).name() << endl;
    cout << "val3: " << typeid(val3).name() << endl;
}

/**
 * 存款
 * @param amount 金额
 * @return 是否存储成功
 */
bool BankAccount::deposit(const int64_t amount) {
    if (amount <= 0 || !isActive) {
        return false;
    }

    // 检查溢出
    if (balance > numeric_limits<int64_t>::max() - amount) {
        cout << "存储金额过大，存储失败" << endl;
        return false;
    }


    balance += amount;

    return true;
}

/**
 * 取款
 * @param amount 金额
 * @return 是否取款成功
 */
bool BankAccount::withdraw(const int64_t amount) {
    if (amount <= 0 || !isActive || balance < amount) return false;

    balance -= amount;
    return true;
}

void BankAccount::addInterest() {
    const double interest = static_cast<double>(balance) * interestRate / 100.0;
    const auto interest_int = static_cast<int64_t>(interest);
    balance += interest_int;
    cout << "添加利息: " << interest_int << " 元" << endl;
}

void BankAccount::display() const {
    cout << "\n账户信息:" << endl;
    cout << "ID: " << accountId << endl;
    cout << "类型: " << static_cast<int>(accountType) << endl;
    cout << "余额: " << balance << " 元" << endl;
    cout << "状态: " << (isActive ? "激活" : "冻结") << endl;
    cout << "利率: " << interestRate << "%" << endl;
}

/**
 * 获取余额
 * @return 余额
 * [[nodiscard]] 提示调用者：返回值不能被忽略，不影响运行，只是增强代码安全性
 * 方法签名后的const：保证这个函数不会修改对象，在方法内部不能修改对象的任何信息
 */
[[nodiscard]] int64_t BankAccount::getBalance() const {
    return balance;
}