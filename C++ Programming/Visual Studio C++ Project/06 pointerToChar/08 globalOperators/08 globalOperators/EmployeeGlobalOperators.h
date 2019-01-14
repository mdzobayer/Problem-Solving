#pragma once
#include <string>
using namespace std;

class EmployeeGlobalOperators
{
public:

	EmployeeGlobalOperators() = default;

	EmployeeGlobalOperators(string nam, double wages, int daysHol)
		: name{ nam }, salary{ wages }, daysHoliday{ daysHol }
	{
		// Employee consturctor
	}

	~EmployeeGlobalOperators() = default;

	string GetName() const
	{
		return name;
	}

	double GetSalary() const
	{
		return salary;
	}

	int GetDaysHoliday() const
	{
		return daysHoliday;
	}

	void SetSalary(double sal)
	{
		salary = sal;
	}

	friend EmployeeGlobalOperators& operator *= (EmployeeGlobalOperators& lhs, const double percentRise);
private:
	string name;
	double salary;
	int daysHoliday;
};

EmployeeGlobalOperators operator + (const EmployeeGlobalOperators& lhs, const EmployeeGlobalOperators& rhs)
{
	EmployeeGlobalOperators temp("Result", lhs.GetSalary() + rhs.GetSalary(), 0);
	return temp;
}

EmployeeGlobalOperators& operator *= (EmployeeGlobalOperators& lhs, const double percentRise)
{
	lhs.salary += (lhs.salary * percentRise);
	return lhs;
}

bool operator == (const EmployeeGlobalOperators& lhs, const EmployeeGlobalOperators& rhs)
{
	return ((lhs.GetName() == rhs.GetName()) &&
			(lhs.GetSalary() == rhs.GetSalary()) &&
			(lhs.GetDaysHoliday() == rhs.GetDaysHoliday()));
}