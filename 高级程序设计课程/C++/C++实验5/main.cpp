#include <iostream>
using namespace std;

class Date
{
private:
	int year;
	int month;
	int day;
	const int day_tab[2][12] = { {31,28,31,30,31,30,31,31,30,31,30,31},//0:平年
								 {31,29,31,30,31,30,31,31,30,31,30,31} };//1:闰年
	//leap(int)：判断指定的年份是否为闰年
	bool leap(int year)
	{
		return (year % 4 == 0 || year % 100 != 0) || (year % 400 == 0);
	}
	//dton(Date&)：将指定日期转换成从0年O月O日起的天数
	int dton(Date& d)
	{
		int days = 0;
		for (int y = 0; y < d.year; y++){day += leap(y) ? 366:365;}
		int temp = leap(d.year) ? 1 : 0;
		for (int m = 0; m < d.month - 1; m++) { days += day_tab[temp][m]; }
		days += d.day;
		return days;
	}
	//ntod(int)：将指定的0年O月O日起的天数转换成对应的日期
	Date ntod(int n)
	{
		int y = 0, m = 1, d = 1;
		int days = n;
		while (days > (leap(y) ? 366 : 365)) { days -= leap(y) ? 366 : 365; y++; }
		int temp = leap(y) ? 1 : 0;
		while (days > day_tab[temp][m - 1]) { days -= day_tab[temp][m - 1]; m++; }
		d = days;
		return Date(y, m, d);
	}
public:
	//构造函数
	Date(int y = 2000, int m = 1, int d = 1) { year = y; month = m; day = d; }
	void input() { cout << "input year mouth day:"; cin >> year >> month >> day; }
	void show()const { cout << year << "-" << month << "-" << day; }
	//重载+
	Date operator+(int days)
	{
		int total_days = dton(*this) + days;
		return ntod(total_days);
	}
	//重载-
	Date operator-(int days)
	{
		int total_days = dton(*this) - days;
		return ntod(total_days);
	}
	//重载-
	int operator-( Date & D)
	{
		return dton(*this) - dton(D);
	}
};

int main()
{
	Date date1, date2;
	int days;
	cout << "的一个日期：" << endl;
	date1.input();
	cout << "你输入的第一个日期是：";
	date1.show();
	cout << endl;
	//加上天数
	cout << "输入要加上的天数：";
	cin >> days;
	Date result1 = date1 + days;
	cout << "加上" << days << "天之后的日期是：";
	result1.show();
	cout << endl << endl;
	//减上天数
	cout << "输入要减去的天数：";
	cin >> days;
	Date result2 = date1 - days;
	cout << "减去" << days << "天之后的日期是：";
	result2.show();
	cout << endl << endl;
	//计算两个日期之差
	cout << "jisuanlianggeriqizhicha" << endl;
	cout << "输入第二个日期：";
	date2.input();
	cout << "第二个日期是：";
	date2.show();
	cout << endl;
	int chazhi = date1 - date2;
	cout << "两个日起至察：" << chazhi << "天" << endl;
	return 0;
}