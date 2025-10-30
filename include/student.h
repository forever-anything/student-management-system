// include/Student.h
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

class Student {
public:
    Student(int id = 0, const std::string& name = "", int age = 0, 
            const std::string& major = "", double gpa = 0.0);
    
    // Getter 方法
    int getId() const;
    std::string getName() const;
    int getAge() const;
    std::string getMajor() const;
    double getGpa() const;
    
    // Setter 方法
    void setName(const std::string& name);
    void setAge(int age);
    void setMajor(const std::string& major);
    void setGpa(double gpa);
    
    // 显示学生信息
    void display() const;
    
    // 重载操作符
    bool operator==(const Student& other) const;
    
private:
    int id;
    std::string name;
    int age;
    std::string major;
    double gpa;
};

#endif // STUDENT_H