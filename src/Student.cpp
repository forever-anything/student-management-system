// src/Student.cpp
#include "Student.h"
#include <iomanip>

Student::Student(int id, const std::string& name, int age, 
                 const std::string& major, double gpa)
    : id(id), name(name), age(age), major(major), gpa(gpa) {}

int Student::getId() const { return id; }
std::string Student::getName() const { return name; }
int Student::getAge() const { return age; }
std::string Student::getMajor() const { return major; }
double Student::getGpa() const { return gpa; }

void Student::setName(const std::string& name) { this->name = name; }
void Student::setAge(int age) { this->age = age; }
void Student::setMajor(const std::string& major) { this->major = major; }
void Student::setGpa(double gpa) { this->gpa = gpa; }

void Student::display() const {
    std::cout << "学号: " << id << "\n"
              << "姓名: " << name << "\n"
              << "年龄: " << age << "\n"
              << "专业: " << major << "\n"
              << "GPA: " << std::fixed << std::setprecision(2) << gpa << "\n"
              << "------------------------" << std::endl;
}

bool Student::operator==(const Student& other) const {
    return id == other.id;
}