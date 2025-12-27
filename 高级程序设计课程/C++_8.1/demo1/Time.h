#include<iostream>
using namespace std;
class Time {
public:
	int hour;
	int minute;
	int second;
	double result;
	friend ostream& operator<<(ostream& output, Time &time);
	friend istream& operator>>(istream& input, Time &time);
};
#pragma once
