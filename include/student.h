//
// Created by 大江流韵 on 2026/4/7.
//

#ifndef CPP_BASIC_STUDENT_H
#define CPP_BASIC_STUDENT_H
#include <string>

class Student {
private:
    std::string name;
    std::string gender;
    int age = 18;

public:
    // setter
    void setName(const std::string & name);
    void setGender(const std::string & gender);
    void setAge(const int & age);

    // getter
    [[nodiscard]] std::string getName() const;
    [[nodiscard]] std::string getGender() const;
    [[nodiscard]] int getAge() const;
};

#endif //CPP_BASIC_STUDENT_H