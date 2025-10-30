// src/Database.cpp
#include "Database.h"
#include <algorithm>
#include <numeric>

Database::Database() {
    // 可以在这里初始化一些测试数据
}

Database::~Database() {
    // 清理资源
}

bool Database::addStudent(const Student& student) {
    if (studentExists(student.getId())) {
        return false; // 学号已存在
    }
    students.push_back(student);
    return true;
}

bool Database::deleteStudent(int id) {
    auto it = std::remove_if(students.begin(), students.end(),
        [id](const Student& s) { return s.getId() == id; });
    
    if (it != students.end()) {
        students.erase(it, students.end());
        return true;
    }
    return false;
}

bool Database::updateStudent(const Student& student) {
    for (auto& s : students) {
        if (s.getId() == student.getId()) {
            s = student;
            return true;
        }
    }
    return false;
}

Student* Database::findStudent(int id) {
    auto it = std::find_if(students.begin(), students.end(),
        [id](const Student& s) { return s.getId() == id; });
    
    return (it != students.end()) ? &(*it) : nullptr;
}

std::vector<Student> Database::getAllStudents() const {
    return students;
}

std::vector<Student> Database::findStudentsByName(const std::string& name) const {
    std::vector<Student> result;
    std::copy_if(students.begin(), students.end(), std::back_inserter(result),
        [&name](const Student& s) { return s.getName().find(name) != std::string::npos; });
    return result;
}

std::vector<Student> Database::findStudentsByMajor(const std::string& major) const {
    std::vector<Student> result;
    std::copy_if(students.begin(), students.end(), std::back_inserter(result),
        [&major](const Student& s) { return s.getMajor() == major; });
    return result;
}

int Database::getStudentCount() const {
    return students.size();
}

double Database::getAverageGpa() const {
    if (students.empty()) return 0.0;
    
    double total = std::accumulate(students.begin(), students.end(), 0.0,
        [](double sum, const Student& s) { return sum + s.getGpa(); });
    
    return total / students.size();
}

bool Database::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return false;
    
    students.clear();
    int id, age;
    std::string name, major;
    double gpa;
    
    while (file >> id >> name >> age >> major >> gpa) {
        students.emplace_back(id, name, age, major, gpa);
    }
    
    file.close();
    return true;
}

bool Database::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) return false;
    
    for (const auto& student : students) {
        file << student.getId() << " " << student.getName() << " "
             << student.getAge() << " " << student.getMajor() << " "
             << student.getGpa() << "\n";
    }
    
    file.close();
    return true;
}

int Database::generateId() const {
    static int nextId = 1000;
    return nextId++;
}

bool Database::studentExists(int id) const {
    return std::any_of(students.begin(), students.end(),
        [id](const Student& s) { return s.getId() == id; });
}