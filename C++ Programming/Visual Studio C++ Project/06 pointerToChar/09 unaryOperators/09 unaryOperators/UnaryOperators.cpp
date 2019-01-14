#include <iostream>
using namespace std;

class Time
{
public:
	// required constructor
	Time()
		: hours{ 0 }, minutes{ 0 }
	{
	}
	Time(int h, int s)
		: hours{ h }, minutes{ s }
	{
	}
	// method to display time
	void displayTime()
	{
		cout << "H: " << hours << " M: " << minutes << endl;
	}
	// overloaded prefix ++ operator
	Time& operator++()
	{
		++minutes;	// increment this object
		if (minutes >= 60)
		{
			++hours;
			minutes -= 60;
		}
		return *this;
	}
	// overloaded postfix ++ operator
	Time operator ++ (int)
	{
		// save the orignal value
		Time T(hours, minutes);
		// increment this object
		++minutes;
		if (minutes >= 60)
		{
			++hours;
			minutes -= 60;
		}
		return (T);
	}
	

private:
	int hours;		// 0 to 23
	int minutes;	// 0 to 59
};

int main() {

	Time T1(11, 59), T2(10, 40);

	++T1;
	T1.displayTime();
	++T1;
	T1.displayTime();

	T2++;
	T2.displayTime();
	T2++;
	T2.displayTime();

	Time T3;
	T3 = ++T1;
	T1.displayTime();
	T3.displayTime();
	T3 = T1++;
	T1.displayTime();
	T3.displayTime();

	return (0);
}