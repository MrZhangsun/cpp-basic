## C++命名规范

| 类型           | 命名规则             | 示例                   | 说明          |
|--------------|------------------|----------------------|-------------|
| 类（Class）     | PascalCase       | UserService          | 大驼峰，名词      |
| 结构体（struct）  | PascalCase       | UserInfo             | 和类一致        |
| 函数（Function） | camelCase        | getUserName()        | 动词开头        |
| 变量（Variable） | camelCase        | userAge              | 清晰语义        |
| 成员变量         | camelCase + `_`  | userAge_             | 区分局部变量 ⭐    |
| 常量（const）    | `k` + PascalCase | kMaxSize             | 全局/类内常量     |
| 宏（#define）   | 全大写 + `_`        | MAX_BUFFER_SIZE      | 避免使用，必要时才用  |
| 枚举（enum）     | PascalCase       | ColorType            | 类型名         |
| 枚举值          | PascalCase       | Red, Green           | 不用全大写（现代风格） |
| 命名空间         | snake_case       | user_system          | 小写+下划线      |
| 文件名          | snake_case       | user_service.cpp     | 和模块一致       |
| 目录名          | snake_case       | user_service/        | 清晰分层        |
| 布尔变量         | is/has/can 开头    | isValid              | 强语义 ⭐       |
| 指针变量         | camelCase        | userPtr              | 不强制 p_ 前缀   |
| 引用变量         | camelCase        | userRef              | 一般不用特殊标记    |
| 静态变量         | camelCase 或 k    | instance_ / kDefault | 看语义         |
| 全局变量         | 不推荐              | g_config（慎用）         | 尽量避免        |