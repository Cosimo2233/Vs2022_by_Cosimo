#include<iostream>

#include"Student.h"
using namespace std;
int main()
{
	char filename[] = "E:\\stu.txt";
	Student stu1, stu2;
	cout << "输入学生数据:" << endl;
	cout << "学号: ";
	string no;
	cin >> no;
	stu1.setNo(no);
	cout << "姓名: ";
	string name;
	cin >> name;
	stu1.setName(name);
	cout << "性别: ";
	string sex;
	cin >> sex;
	stu1.setSex(sex);
	cout << "专业: ";
	string major;
	cin >> major;
	stu1.setMajor(major);
	cout << "电话: ";
	string phone;
	cin >> phone;
	stu1.setPhone(phone);
	cout << "地址: ";
	string addr;
	cin >> addr;
	stu1.setAddr(addr);
	stu1.writeTo(filename);
	cout << endl;
	stu2.readFrom(filename);
	cout << "输出学生数据:" << endl;
	cout << "学号: " << stu2.getNo() << endl;
	cout << "姓名: " << stu2.getName() << endl;
	cout << "性别: " << stu2.getSex() << endl;
	cout << "专业: " << stu2.getMajor() << endl;
	cout << "电话: " << stu2.getPhone() << endl;
	cout << "地址: " << stu2.getAddr() << endl;
}