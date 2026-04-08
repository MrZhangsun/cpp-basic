//
// Created by 大江流韵 on 2026/4/7.
//

#pragma once

class DataType {
public:
    static void demoIntegerOverflow();
    static void demoFloatingPrecision();
    static void demoTypeConversion();
    static void demoSizeAndLimits();
    static void demoBitOperations();
    static void demoCharAndStrings();
    static void demoTypeBestPractices();
    static void demoTypeDeduction();
};
// 综合应用：模拟银行账户系统
class BankAccount {
    int64_t balance; // 使用64位整数防止溢出
    uint32_t accountId;
    uint8_t accountType; // 账户类型，1:储蓄 2:支票 3:投资
    bool isActive;
    double interestRate; // 年利率
public:
    // BankAccount(const uint32_t id, const uint8_t type, const double rate) {
    //     this->account_id = id;
    //     this->account_type = type;
    //     this->interest_rate = rate;
    //     this->balance = 0;
    //     this->is_active = true;
    // }
    /**
     * 无参构造
     */
    BankAccount() = default;
    /**
     * 构造函数
     * @param id 账户ID
     * @param type 账户类型
     * @param rate 年利率
     */
    BankAccount(const uint32_t id, const uint8_t type, const double rate)
    : balance(0), accountId(id), accountType(type), isActive(true), interestRate(rate) {}

    /**
     * 存款
     * @param amount 金额
     * @return 是否存储成功
     */
    bool deposit(int64_t amount);

    /**
     * 取款
     * @param amount 金额
     * @return 是否取款成功
     */
    bool withdraw(int64_t amount);

    /**
     * 计算利息
     */
    void addInterest();

    /**
     * 显示账户信息
     */
    void display() const;

    /**
     * 获取余额
     * @return 账户余额
     */
    [[nodiscard]] int64_t getBalance() const;
};