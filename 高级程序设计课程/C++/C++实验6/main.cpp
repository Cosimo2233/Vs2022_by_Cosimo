#include <iostream> 
#include "Person.h"

int main()
{
    const int MAX = 10;
    WorkingStudent wsList[MAX];
    StudyingTeacher stList[MAX];
    int wsCount = 1, stCount = 1;

    // 初始化数据
    wsList[0] = WorkingStudent("家里蹲大学",
        "S2023002", "14板", "维修技术", 666,
        "T002", "讲师", 3000,
        "丽丝", 'F', 30);

    stList[0] = StudyingTeacher("123123", "副教授", 13000.0,
        "114514", "1班", "土木工程", 670.0,
        "祥子", 'F', 35);

    int choice;

    do {
        cout << "1. 添加在职研究生" << endl;
        cout << "2. 添加在读教师" << endl;
        cout << "3. 显示所有在职研究生" << endl;
        cout << "4. 显示所有在读教师" << endl;
        cout << "5. 按姓名查找" << endl;
        cout << "6. 修改在职研究生信息" << endl;
        cout << "7. 修改在读教师信息" << endl;
        cout << "0. 退出" << endl;
        cout << "请选择: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (wsCount < MAX) {
                wsList[wsCount].inputWorkingStudent();
                wsCount++;
                cout << "添加成功！" << endl;
            }
            else {
                cout << "存储已满！" << endl;
            }
            break;

        case 2:
            if (stCount < MAX) {
                stList[stCount].inputStudyingTeacher();
                stCount++;
                cout << "添加成功！" << endl;
            }
            else {
                cout << "存储已满！" << endl;
            }
            break;

        case 3:
            if (wsCount == 0) {
                cout << "暂无记录" << endl;
            }
            else {
                for (int i = 0; i < wsCount; i++) {
                    cout << "\n第" << i + 1 << "位：" << endl;
                    wsList[i].displayWorkingStudent();
                }
            }
            break;

        case 4:
            if (stCount == 0) {
                cout << "无" << endl;
            }
            else {
                for (int i = 0; i < stCount; i++) {
                    cout << "\n第" << i + 1 << "位：" << endl;
                    stList[i].displayStudyingTeacher();
                }
            }
            break;

        case 5: {
            string searchName;
            cout << "请输入要查找的姓名: ";
            cin >> searchName;
            bool found = false;

            for (int i = 0; i < wsCount; i++) {
                if (wsList[i].findByName(searchName)) {
                    wsList[i].displayWorkingStudent();
                    found = true;
                    cout << endl;
                }
            }

            for (int i = 0; i < stCount; i++) {
                if (stList[i].findByName(searchName)) {
                    stList[i].displayStudyingTeacher();
                    found = true;
                    cout << endl;
                }
            }

            if (!found) {
                cout << "未找到姓名为 " << searchName << " 的人员" << endl;
            }
            break;
        }

        case 6: {
            string searchName;
            cout << "请输入要修改的在职研究生姓名: ";
            cin >> searchName;
            bool found = false;

            for (int i = 0; i < wsCount; i++) {
                if (wsList[i].findByName(searchName)) {
                    cout << "找到人员，输入新信息：" << endl;
                    wsList[i].inputWorkingStudent();
                    cout << "修改成功！" << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "未找到姓名为 " << searchName << " 的在职研究生" << endl;
            }
            break;
        }

        case 7: {
            string searchName;
            cout << "请输入要修改的在读教师姓名: ";
            cin >> searchName;
            bool found = false;

            for (int i = 0; i < stCount; i++) {
                if (stList[i].findByName(searchName)) {
                    cout << "找到人员，输入新信息：" << endl;
                    stList[i].inputStudyingTeacher();
                    cout << "修改成功！" << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "未找到姓名为 " << searchName << " 的在读教师" << endl;
            }
            break;
        }

        case 0:
            cout << "谢谢使用，再见！" << endl;
            break;

        default:
            cout << "无效选择！" << endl;
        }

    } while (choice != 0);

    return 0;
}