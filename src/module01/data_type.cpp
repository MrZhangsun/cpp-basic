//
// Created by 大江流韵 on 2026/4/7.
//
#include <iostream>
#include <iomanip> // input-output manipulators（输入输出格式控制工具）
#include <limits>
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
    cout << left << setw(15) << name
    << "大小：" << setw(4) << size << "字节"
    << "范围：" << range << endl;
}
// 演示整型溢出
void DataType::demoIntegerOverflow() {
    cout << "\n========== 1. 整型溢出演示 ==========" << endl;
    /* numeric_limits<data_type>: 模板类, 定义在：limits.h中，用于获取某种数据类型的“极限值信息”
     * ::max() 是它的静态方法
    */
    constexpr unsigned int max_unit = numeric_limits<unsigned int>::max();
    cout << "unsigned int 最大值：" << max_unit << endl;
    cout << "最大值+1：" << max_unit + 1 << " (回绕到0)" << endl;
}


