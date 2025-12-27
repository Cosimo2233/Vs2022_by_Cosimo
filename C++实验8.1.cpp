#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>
using namespace std;
class Time
{
private:
    int hour;
    int minute;
    int second;
public:
    Time(int h = 0, int m = 0, int s = 0): hour(h), minute(m), second(s) {}
    friend istream& operator>>(istream& is, Time& t)
    {
        is>>t.hour >> t.minute >> t.second;
        if(is.fail())
        {
            is.clear();
            is.ignore(numeric_limits<streamsize>::max(), '\n');
            throw runtime_error("error!");
        }
        if(t.hour < 0 || t.hour > 23 || t.minute < 0 || t.minute > 59 || t.second < 0 || t.second > 59)
        {
            throw out_of_range("out of range!");
        }
        return is;
    }
    friend ostream& operator<<(ostream& os, const Time& t)
    {
        double decimal_hour = t.hour + t.minute / 60.0 + t.second / 3600.0;
        os << fixed << setprecision(2) << decimal_hour;
        return os;
    }
    double toDecimalHour() const
    {
        return hour + minute / 60.0 + second / 3600.0;
    }
};

int main()
{
    Time t;
    cout << "输入时间（时 分 秒）：";
    try
    {
        cin >> t;
        cout << "小数为：" << t << endl;
    }
    catch(const exception& e)
    {
        cerr << e.what() << endl;
    }
    return 0;
}