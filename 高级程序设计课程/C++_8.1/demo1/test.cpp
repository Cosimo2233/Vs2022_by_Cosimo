#include<iostream>
using namespace std;
#include<fstream>
#include"Time.h"

int main() {
	Time t;
	cout << "输入一个时间<h m s>: " << std::nounitbuf;
	cin >> t;
	if (t.hour > 0 && t.hour < 24 && t.minute > 0 && t.minute < 60 && t.second > 0 && t.second < 60) {
		cout << "输出该时间对应的小数: " << std::nounitbuf;
		cout << t;
	}
	else
		cout<< "输入格式错误！" << endl;

	return 0;
}