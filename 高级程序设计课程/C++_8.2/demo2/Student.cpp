#include "Student.h"
#include<iostream>
using namespace std;


void Student::writeTo(char filename[])
{
	//实验二部分
	ofstream outfile;
	outfile.open(filename, ios::binary);
	outfile << this->no << endl;
	outfile << this->name << endl;
	outfile << this->sex << endl;
	outfile << this->major << endl;
	outfile << this->phone << endl;
	outfile << this->addr << endl;
	outfile.close();
	
	//实验三部分
	//fstream binfile;
	//const char* no, * name, * sex, * major, * phone, * addr;
	//no = this->no.c_str();
	//name = this->name.c_str();
	//sex = this->sex.c_str();
	//major = this->major.c_str();
	//phone = this->phone.c_str();
	//addr = this->addr.c_str();
	//binfile.open(filename, ios::binary | ios::out | ios::trunc);
	//binfile.write(no, 20 * sizeof(char));
	//binfile.write(name, 20 * sizeof(char));
	//binfile.write(sex, 20 * sizeof(char));
	//binfile.write(major, 20 * sizeof(char));
	//binfile.write(phone, 20 * sizeof(char));
	//binfile.write(addr, 20 * sizeof(char));
	//binfile.close();
	
}

void Student::readFrom(char filename[])
{
	//实验二部分
	ifstream infile;
	infile.open(filename);
	infile >> this->no >> this->name >> this->sex >> this->major >> this->phone >> this->addr;
	infile.close();

	//实验三部分
	//ifstream binfile;
	//binfile.open(filename, ios::binary);
	//char temp[20];
	//binfile.read(reinterpret_cast<char*>(temp), 20 * sizeof(char));
	//this->no = temp;
	//binfile.read(reinterpret_cast<char*>(temp), 20 * sizeof(char));
	//this->name = temp;
	//binfile.read(reinterpret_cast<char*>(temp), 20 * sizeof(char));
	//this->sex = temp;
	//binfile.read(reinterpret_cast<char*>(temp), 20 * sizeof(char));
	//this->major = temp;
	//binfile.read(reinterpret_cast<char*>(temp), 20 * sizeof(char));
	//this->phone = temp;
	//binfile.read(reinterpret_cast<char*>(temp), 20 * sizeof(char));
	//this->addr = temp;
	//binfile.close();
}

void Student::setNo(string no)
{
	this->no = no;
}

void Student::setName(string name)
{
	this->name = name;
}

void Student::setSex(string sex)
{
	this->sex = sex;
}

void Student::setMajor(string major)
{
	this->major = major;
}

void Student::setPhone(string phone)
{
	this->phone = phone;
}

void Student::setAddr(string addr)
{
	this->addr = addr;
}

string Student::getNo()
{
	return this->no;
}

string Student::getName()
{
	return this->name;
}

string Student::getSex()
{
	return this->sex;
}

string Student::getMajor()
{
	return this->major;
}

string Student::getPhone()
{
	return this->phone;
}

string Student::getAddr()
{
	return this->addr;
}