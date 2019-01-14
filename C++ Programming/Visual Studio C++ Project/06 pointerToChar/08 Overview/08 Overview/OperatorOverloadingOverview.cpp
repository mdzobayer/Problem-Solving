#include <iostream>
#include "EmployeeOOOverview.h"
using namespace std;

int main() 
{
	EmployeeOOOverview emp1("Fred Flintstone", 10000.99, 5);
	EmployeeOOOverview emp2("Fred Flintstone", 10000.99, 5);
	EmployeeOOOverview emp3("Batman", 50000.55, 1);
	EmployeeOOOverview emp4("Popeye", 9999.99, 30);
	EmployeeOOOverview emp5;

	emp5 = emp1 + emp3 + emp4;	// Add EmployeeOOOverview objects together
	double averageSalary = emp5.GetSalary() / 3;

	cout.precision(2);
	cout << "Average salary for all employees is " << fixed << averageSalary << endl;
	
	++emp1;	// Increment emp1 - give Fred an extra days holiday
	emp1++;	// Increment emp1 - give Fred an extra days holiday

	emp4 *= 0.1;	// Give Popeye a 10% pay rise

	cout.precision(2);
	cout << "Popeye new salary = " << fixed << emp4.GetSalary() << endl;

	if (emp1 == emp2)
	{
		cout << "Duplicate employee" << endl;
	}
	return (0);
}