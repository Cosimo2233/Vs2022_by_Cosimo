#include<string>
#include<fstream>
using namespace std;
class Student {
private:
	string no;
	string name;
	string sex;
	string major;
	string phone;
	string addr;
public:
	Student() {}
	void writeTo(char filename[]);
	void readFrom(char filename[]);

	void setNo(string no);
	void setName(string name);
	void setSex(string sex);
	void setMajor(string major);
	void setPhone(string phone);
	void setAddr(string addr);

	string getNo();
	string getName();
	string getSex();
	string getMajor();
	string getPhone();
	string getAddr();
};
#pragma once
