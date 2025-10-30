// include/Database.h
#ifndef DATABASE_H
#define DATABASE_H

#include "Student.h"
#include <vector>
#include <string>
#include <fstream>

class Database {
public:
    Database();
    ~Database();
    
    // 基本操作
    bool addStudent(const Student& student);
    bool deleteStudent(int id);
    bool updateStudent(const Student& student);
    Student* findStudent(int id);
    std::vector<Student> getAllStudents() const;
    
    // 查询功能
    std::vector<Student> findStudentsByName(const std::string& name) const;
    std::vector<Student> findStudentsByMajor(const std::string& major) const;
    
    // 统计功能
    int getStudentCount() const;
    double getAverageGpa() const;
    
    // 文件操作
    bool loadFromFile(const std::string& filename);
    bool saveToFile(const std::string& filename);
    
private:
    std::vector<Student> students;
    
    int generateId() const;
    bool studentExists(int id) const;
};

#endif // DATABASE_H