#include <iostream>
#include "student.h"
#include <algorithm>
using namespace std;

void showMenu();
void inputStudents(Student**& students, int& n);
void showAll(Student** students, int n);
void modifyStudent(Student** students, int n);
void queryStudent(Student** students, int n);
void rankStudents(Student** students, int n);
void checkFails(Student** students, int n);
void calcAllAverages(Student** students, int n);
// 比较函数
bool compare(Student* a, Student* b) 
{
    return a->getAverage() > b->getAverage();
}

int main()
{
    Student** students = nullptr;
    int n = 0;
    int choice;

    do
    {
        showMenu();
        cout << "请选择：";
        cin >> choice;
        switch (choice)
        {
        case 1:inputStudents(students, n); break;
        case 2:showAll(students, n); break;
        case 3:modifyStudent(students, n); break;
        case 4:queryStudent(students, n); break;
        case 5:rankStudents(students, n); break;
        case 6:calcAllAverages(students, n); break;
        case 7:checkFails(students, n); break;
        case 8:Student::courceStats(students, n); break;
        case 0:cout << "谢谢！" << endl; break;
        default:cout << "无效！" << endl;           
        }
        if (choice != 0)
        {
            cout << "按回车继续...";
            cin.ignore();
            cin.get();
        }
    } while (choice != 0);
    for (int i = 0; i < n; i++)
    {
        delete students[i];
    }
    delete[] students;

    cout << "本程序由AAA电子厂张师傅完成..." << endl;
    return 0;
}

void showMenu()
{
    
    cout << "1. 输入学生信息" << endl;
    cout << "2. 显示所有学生" << endl;
    cout << "3. 修改学生信息" << endl;
    cout << "4. 查询学生" << endl;
    cout << "5. 按成绩排名" << endl;
    cout << "6. 计算平均分" << endl;
    cout << "7. 检查不及格" << endl;
    cout << "8. 课程统计" << endl;
    cout << "0. 退出" << endl;
    
}
//输入学生
void inputStudents(Student**& students, int& n)
{
    cout << "输入数量：";
    cin >> n;
    //释放旧内存
    if (students != nullptr)
    {
        for (int i = 0; i < n; i++)
        {
            delete students[i];  
        }
        delete[] students;       
        students = nullptr;
    }
        //动态分配内存
        students = new Student * [n];
        for (int i = 0; i < n; i++)
        {
            cout << "\n   第" << i + 1 << "个学生   " << endl;
            students[i] = new Student();
            students[i]->input();
            students[i]->inputScores();

        }
}
//显示所有学生
void showAll(Student** students, int n)
{
    if (n == 0)
    {
        cout << "没有数据！" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        students[i]->show();
    }
}
//修改学生
void modifyStudent(Student** students, int n)
{
    if (n == 0)
    {
        cout << "没有数据！" << endl;
        return;
    }
    string searchId;
    cout << "输入要修改的学生学号:";
    cin >> searchId;

    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (students[i]->matchId(searchId))
        {
            students[i]->modify();
            found = true;
            break;
        }
    }
    if (!found) { cout << "找不到！" << endl; }
}

//查询学生
void queryStudent(Student** students, int n)
{
    if (n == 0)
    {
        cout << "没有数据！" << endl;
        return;
    }
    int choice;
    cout << "查询方式：1->学号；2->姓名";
    cin >> choice;
    if (choice == 1)
    {
        string id;
        cout << "请输入学号：";
        cin >> id;
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            if (students[i]->matchId(id))
            {
                students[i]->show();
                found = true;
                
            }
        }
        if (!found) cout << "找不到！" << endl;
    }
    else if (choice == 2) {
        string name;
        cout << "输入姓名: ";
        cin >> name;

        bool found = false;
        for (int i = 0; i < n; i++) {
            if (students[i]->matchName(name))
            {
                students[i]->show();
                found = true;
                break;
            }
        }
        if (!found) cout << "找不到！" << endl;
    }
}
// 成绩排名
void rankStudents(Student** students, int n) 
{
    if (n == 0) 
    {
        cout << "没有学生数据！" << endl;
        return;
    }

    // 复制指针数组
    Student** temp = new Student * [n];
    for (int i = 0; i < n; i++) 
    { 
        temp[i] = students[i];
    }

    // 排序
    sort(temp, temp + n, compare);

    // 显示排名
    cout << "\n     成绩排名    " << endl;
    cout << "名次\t学号\t姓名\t性别\t平均分" << endl;
    for (int i = 0; i < n; i++) {
        temp[i]->showSimple(i + 1);
    }

    delete[] temp;
}
// 计算所有平均分
void calcAllAverages(Student** students, int n) {
    if (n == 0) {
        cout << "没有学生数据！" << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        students[i]->CalculateAverage(true);  // 使用重载函数，显示详情
    }
}

// 检查不及格
void checkFails(Student** students, int n) {
    if (n == 0) {
        cout << "没有学生数据！" << endl;
        return;
    }

    cout << "\n\t不及格学生 \t" << endl;
    cout << "学号\t\t姓名\t\t" << endl;
  

    int failCount = 0;

    for (int i = 0; i < n; i++) {
     
        students[i]->check();

      
        if (students[i]->getHasFailed()) {
            failCount++;
            cout << students[i]->getId() << "\t"
                << students[i]->getName() << "\t" << endl;
        }
    }

    if (failCount == 0) {
        cout << "全部及格！" << endl;
    }
    else {
        cout << "\n总计: " << failCount << "名学生有不及格科目" << endl;
    }
}