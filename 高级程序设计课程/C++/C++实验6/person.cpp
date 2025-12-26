#include "Person.h"

Person::Person(string n, char g, int a) : name(n), gender(g), age(a) {}

void Person::setPerson(string n, char g, int a)
{
    name = n; gender = g; age = a;
}

void Person::displayPerson()
{
    cout << "姓名: " << name << endl;
    cout << "性别: " << gender << endl;
    cout << "年龄: " << age << endl;
}

string Person::getName() { return name; }
char Person::getGender() { return gender; }
int Person::getAge() { return age; }

Teacher::Teacher(string id, string t, double s, string n, char g, int a)
    : Person(n, g, a), teacherId(id), title(t), salary(s) {
}

void Teacher::setTeacher(string id, string t, double s)
{
    teacherId = id;
    title = t;
    salary = s;
}

void Teacher::displayTeacher()
{
    displayPerson();
    cout << "工号: " << teacherId << endl;
    cout << "职称: " << title << endl;
    cout << "工资: " << salary << endl;
}

string Teacher::getTeacherId() const { return teacherId; }
string Teacher::getTitle() const { return title; }
double Teacher::getSalary() const { return salary; }

void Teacher::setTitle(string t) { title = t; }
void Teacher::setSalary(double s) { salary = s; }

void Teacher::inputTeacher()
{
    cout << "输入姓名: ";
    cin >> name;
    cout << "输入性别(M/F): ";
    cin >> gender;
    cout << "输入年龄: ";
    cin >> age;
    cout << "输入工号: ";
    cin >> teacherId;
    cout << "输入职称: ";
    cin >> title;
    cout << "输入工资: ";
    cin >> salary;
}

Student::Student(string id, string c, string m, double s, string n, char g, int a)
    : Person(n, g, a), studentId(id), className(c), major(m), score(s) {
}

void Student::setStudent(string id, string c, string m, double s)
{
    studentId = id;
    className = c;
    major = m;
    score = s;
}

void Student::displayStudent()
{
    displayPerson();
    cout << "学号: " << studentId << endl;
    cout << "班级: " << className << endl;
    cout << "专业: " << major << endl;
    cout << "入学成绩: " << score << endl;
}

string Student::getStudentId() const { return studentId; }
string Student::getClassName() const { return className; }
string Student::getMajor() const { return major; }
double Student::getEntranceScore() const { return score; }

void Student::inputStudent()
{
    cout << "输入姓名: ";
    cin >> name;
    cout << "输入性别(M/F): ";
    cin >> gender;
    cout << "输入年龄: ";
    cin >> age;
    cout << "输入学号: ";
    cin >> studentId;
    cout << "输入班级: ";
    cin >> className;
    cout << "输入专业: ";
    cin >> major;
    cout << "输入入学成绩: ";
    cin >> score;
}

WorkingStudent::WorkingStudent(string w, string sid, string c, string m, double es,
    string tid, string t, double sal,
    string n, char g, int a)
    : Person(n, g, a),
    Student(sid, c, m, es, n, g, a),
    Teacher(tid, t, sal, n, g, a),
    workshop(w) {
}

void WorkingStudent::setWorkingStudent(string w, string sid, string c, string m, double es,
    string tid, string t, double sal,
    string n, char g, int a)
{
    workshop = w;
    setPerson(n, g, a);
    setStudent(sid, c, m, es);
    setTeacher(tid, t, sal);
}

void WorkingStudent::displayWorkingStudent()
{
    displayPerson();
    cout << "学号: " << studentId << endl;
    cout << "班级: " << className << endl;
    cout << "专业: " << major << endl;
    cout << "入学成绩: " << score << endl;
    cout << "工号: " << teacherId << endl;
    cout << "职称: " << getTitle() << endl;
    cout << "工资: " << getSalary() << endl;
    cout << "工作单位: " << workshop << endl;
}

string WorkingStudent::getworkshop() { return workshop; }

void WorkingStudent::setWorkShop(string w) { workshop = w; }

void WorkingStudent::inputWorkingStudent()
{
    cout << " 输入在职研究生信息 " << endl;
    cout << "输入姓名: ";
    cin >> name;
    cout << "输入性别(M/F): ";
    cin >> gender;
    cout << "输入年龄: ";
    cin >> age;
    cout << "输入学号: ";
    cin >> studentId;
    cout << "输入班级: ";
    cin >> className;
    cout << "输入专业: ";
    cin >> major;
    cout << "输入入学成绩: ";
    cin >> score;
    cout << "输入工号: ";
    cin >> teacherId;
    string tempTitle;
    double tempSalary;
    cout << "输入职称: ";
    cin >> tempTitle;
    setTitle(tempTitle);
    cout << "输入工资: ";
    cin >> tempSalary;
    setSalary(tempSalary);
    cout << "输入工作单位: ";
    cin >> workshop;
}

bool WorkingStudent::findByName(string searchName)
{
    return name == searchName;
}

StudyingTeacher::StudyingTeacher(string tid, string t, double sal,
    string sid, string c, string m, double es,
    string n, char g, int a)
    : Person(n, g, a),
    Teacher(tid, t, sal, n, g, a),
    Student(sid, c, m, es, n, g, a) {
}

void StudyingTeacher::setStudyingTeacher(string tid, string t, double sal,
    string sid, string c, string m, double es,
    string n, char g, int a)
{
    setPerson(n, g, a);
    setTeacher(tid, t, sal);
    setStudent(sid, c, m, es);
}

void StudyingTeacher::displayStudyingTeacher()
{
    displayPerson();
    cout << "工号: " << teacherId << endl;
    cout << "职称: " << getTitle() << endl;
    cout << "工资: " << getSalary() << endl;
    cout << "学号: " << studentId << endl;
    cout << "班级: " << className << endl;
    cout << "专业: " << major << endl;
    cout << "入学成绩: " << score << endl;
}

void StudyingTeacher::inputStudyingTeacher()
{
    cout << "输入在读教师信息 " << endl;
    cout << "输入姓名: ";
    cin >> name;
    cout << "输入性别(M/F): ";
    cin >> gender;
    cout << "输入年龄: ";
    cin >> age;
    cout << "输入工号: ";
    cin >> teacherId;
    string tempTitle;
    double tempSalary;
    cout << "输入职称: ";
    cin >> tempTitle;
    setTitle(tempTitle);
    cout << "输入工资: ";
    cin >> tempSalary;
    setSalary(tempSalary);
    cout << "输入学号: ";
    cin >> studentId;
    cout << "输入班级: ";
    cin >> className;
    cout << "输入专业: ";
    cin >> major;
    cout << "输入入学成绩: ";
    cin >> score;
}

bool StudyingTeacher::findByName(string searchName)
{
    return name == searchName;
}