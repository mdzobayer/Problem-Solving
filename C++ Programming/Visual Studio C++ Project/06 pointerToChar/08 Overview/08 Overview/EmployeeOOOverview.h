#pragma once
#include <string>
using namespace std;

class EmployeeOOOverview
{
public:

	EmployeeOOOverview() = default;

	EmployeeOOOverview(string nam, double wages, int daysHol)
		: name{ nam }, salary{ wages }, daysHoliday{ daysHol }
	{
		// Employee consturctor
	}

	~EmployeeOOOverview() = default;

	string GetName() const
	{
		return name;
	}

	double GetSalary() const
	{
		return salary;
	}

	int GetDayHoliday() const
	{
		return daysHoliday;
	}
private:
	string name;
	double salary;
	int daysHoliday;
};