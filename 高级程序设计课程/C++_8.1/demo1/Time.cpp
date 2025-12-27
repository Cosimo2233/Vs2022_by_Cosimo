#include"Time.h"
#include <iomanip>


ostream& operator<<(ostream& output, Time& time)
{
	time.result = time.hour + time.minute / 60.0 + time.second / 3600.0;
	output << fixed << setprecision(4) << time.result;
	return output;
}

istream& operator>>(istream& input, Time& time)
{
	input >> time.hour >> time.minute >> time.second;
	return input;
}
