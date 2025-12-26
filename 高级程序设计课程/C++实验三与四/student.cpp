#include <iostream>
#include "student.h"
#include <algorithm>

using namespace std;

//构造函数
Student::Student()
{
	id = "0000000";
	name = "无";
	age = 0;
	gender = 'M';
	type = 1;
	scores = new float[4] {0, 0, 0,0};
	average = 0;
	hasFailed = false;
}
//重载构造函数
Student::Student(string i, string n, int a, char g, int t)
{
	id = i;
	name = n;
	age = a;
	gender = g;
	type = (t == 2) ? 2 : 1;
	scores = new float[type == 1 ? 4 : 5];
	for (int i = 0; i < (type == 1 ? 4 : 5); i++) { scores[i] = 0; }
	average = 0;
	hasFailed = false;
}
//析构函数
Student::~Student()
{
	delete[]scores;
}
//输入信息
void Student::input()
{
	cout << "学号：";
	cin >> id;
	if (id.length() != 10)
	{
		cout << "学号必须是10位数。" << endl;
		return;
	}
	cout << "姓名：";
	cin >> name;
	if(name.empty() || name.length() > 8)
	{
		cout << "姓名不得超过四个汉字！" << endl;
		return;
	}
	cout << "年龄：";
	cin >> age;
	cout << "性别（M/F）：";
	cin >> gender;
	if (gender != 'M' && gender != 'F')
	{
		cout << "错误，性别只能是男女。" << endl;
		return;
	}
	cout << "课程类别（输入1为四门课，输入2为五门课）：";
	cin >> type;
	delete[] scores;
	int n = (type == 1) ? 4 : 5;
	scores = new float[n];
	for (int i = 0; i < n; i++) { scores[i] = 0; }
	
}
//输入成绩
void Student::inputScores()
{
	cout << "\n输入" << name << "的成绩：" << endl;
	int n = (type == 1) ? 4 : 5;
	for (int i = 0; i < n; i++)
	{
		cout << "课程" << i + 1 << ":";
		cin >> scores[i];
		if (scores[i] < 0 || scores[i] >100)
		{
			cout << "错误，成绩只能在0~100" << endl;
			return;
		}
	}
	CalculateAverage();
	check();
}
//计算平均分
void Student::CalculateAverage() {
	int n = (type == 1) ? 4 : 5;
	float sum = 0;
	for (int i = 0; i < n; i++) sum += scores[i];
	average = sum / n;
}

void Student::CalculateAverage(bool show)
{
	if (show)
	{
		cout << "\n" << name << "的成绩：" << endl;
		int n = (type == 1) ? 4 : 5;
		for(int i=0;i<n;i++)
		{
			cout << "课程" << i+1 << ":" << scores[i] << endl;
		}
	}
	CalculateAverage();
	if (show)cout << "平均分：" << average << endl;
}
//检查是否及格
void Student::check()
{
	hasFailed = false;
	int n = (type == 1) ? 4 : 5;
	for (int i = 0; i < n; i++)
	{
		if(scores[i]<60)
		{
			hasFailed = true;
			return;
		}
	}
}
//显示详细信息
void Student::show()
{
	cout << "\n		学生信息	    	" << endl;
	cout << "学号:" << id << endl;
	cout << "姓名：" << name << endl;
	cout << "年龄：" << age << endl;
	cout << "性别：" << (gender == 'M' ? "南" : "女") << endl;
	cout << "课程类别：" << (type == 1 ? "四门课" : "五门课") << endl;
	int n = (type == 1) ? 4 : 5;
	cout << "成绩：";
	for (int i = 0; i < n; i++)
	{
		cout << scores[i];
		if (i < n - 1) { cout << ","; }	
	}
	cout << endl;
	cout << "平均分:" << average << endl;
	cout << "是否及格：" << (hasFailed ? "不及格" :"及格") << endl;
}
//显示详细信息
void Student::showSimple(int rank)
{
	cout << rank << "\t" << id << "\t" << name << "\t" 
		 << (gender == 'M' ? "南" : "女") << "\t" << average << endl;
}
//修改信息
void Student::modify()
{
	cout << "\n修改" << name << "的信息" << endl;
	cout << "1.修改基本信息" << endl;
	cout << "2.修改成绩" << endl;
	cout << "选择：";
	int choice;
	cin >> choice;
	if (choice == 1) { input(); }
	else if (choice == 2) { inputScores(); }
}
//匹配函数
bool Student::matchId(string searchId)
{
	return id == searchId;
}
bool Student::matchName(string searchName) 
{
	return name == searchName;
}
//单科成绩
float Student::getScore(int i)
{
	int n = (type == 1) ? 4 : 5;
	if (i >= 0 && i < n) { return scores[i]; }
	return 0;
}
//课程统计
void Student::courceStats(Student* students[], int n)
{
	if (n == 0) 
	{
		cout << "无数据。" << endl;
		return;
	}
	// 找到最大课程数
	int maxCourses = 0;
	for (int i = 0; i < n; i++) {
		if (students[i]->getType() == 3 && 5 > maxCourses) maxCourses = 5;
		else if (students[i]->getType() == 1 && 4 > maxCourses) maxCourses = 4;
	}

	cout << "\n\t 课程统计 \t" << endl;
	cout << "课程\t平均分\t最高分\t最低分" << endl;

	for (int course = 0; course < maxCourses; course++) {
		float sum = 0, maxScore = 0, minScore = 100;
		int count = 0;

		for (int i = 0; i < n; i++) {
			if (course < (students[i]->getType() == 1 ? 4 : 5)) {
				float s = students[i]->getScore(course);
				sum += s;
				if (s > maxScore) maxScore = s;
				if (s < minScore) minScore = s;
				count++;
			}
		}

		if (count > 0) {
			float avg = sum / count;
			cout << "课程" << course + 1 << "\t" << avg
				<< "\t" << maxScore << "\t" << minScore << endl;
		}
	}
}