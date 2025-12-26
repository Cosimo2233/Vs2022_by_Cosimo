#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

// 人类
class Person
{
protected:
    string name;
    char gender;
    int age;
public:
    // 构造函数
    Person(string n = "name", char g = 'M', int a = 18);
    // 修改
    void setPerson(string n, char g, int a);
    // 显示信息
    void displayPerson();
    // 查询
    string getName();
    char getGender();
    int getAge();
};

// 教师类
class Teacher : virtual public Person
{
private:
    string title;
    double salary;
protected:
    string teacherId;
public:
    Teacher(string id = "", string t = "", double s = 0.0,
        string n = "", char g = ' ', int a = 18);
    // 设置信息
    void setTeacher(string id, string t, double s);
    // 显示信息
    void displayTeacher();
    // 查询
    string getTeacherId() const;
    string getTitle() const;
    double getSalary() const;
    // 修改信息
    void setTitle(string t);
    void setSalary(double s);
    // 输入教师信息
    void inputTeacher();
};

// 学生类
class Student : virtual public Person
{
protected:
    string studentId;
    string className;
    string major;
    double score;
public:
    Student(string id = "", string c = "", string m = "", double s = 0.0,
        string n = "", char g = ' ', int a = 0);
    // 设置信息
    void setStudent(string id, string c, string m, double s);
    // 显示信息
    void displayStudent();
    // 查询
    string getStudentId() const;
    string getClassName() const;
    string getMajor() const;
    double getEntranceScore() const;
    // 输入学生信息
    void inputStudent();
};

// 在职研究生类
class WorkingStudent : public Student, public Teacher
{
private:
    string workshop;
public:
    WorkingStudent(string w = "",
        string sid = "", string c = "", string m = "", double es = 0.0,
        string tid = "", string t = "", double sal = 0.0,
        string n = "", char g = 'M', int a = 0);
    // 设置信息
    void setWorkingStudent(string w, string sid, string c, string m, double es,
        string tid, string t, double sal,
        string n, char g, int a);
    // 显示信息
    void displayWorkingStudent();
    // 查询
    string getworkshop();
    // 修改
    void setWorkShop(string w);
    // 输入在职研究生信息
    void inputWorkingStudent();
    // 查找函数
    bool findByName(string searchName);
};

// 在读教师类
class StudyingTeacher : public Teacher, public Student
{
public:
    StudyingTeacher(string tid = "", string t = "", double sal = 0.0,
        string sid = "", string c = "", string m = "", double es = 0.0,
        string n = "", char g = ' ', int a = 0);
    // 设置信息
    void setStudyingTeacher(string tid, string t, double sal,
        string sid, string c, string m, double es,
        string n, char g, int a);
    // 显示在读教师信息
    void displayStudyingTeacher();
    // 输入在读教师信息
    void inputStudyingTeacher();
    // 查找函数
    bool findByName(string searchName);
};

#endif // PERSON_H