#include <iostream>
#include <string>
#include <map>
using namespace std;

void MapTest()
{
	cout << "MAP TEST" << endl << "==============" << endl;

	map<int, string> Employees;

	// Assignment using array index notation
	Employees[5234] = "Mike C.";
	Employees[3374] = "Charlie M.";
	Employees[1923] = "David D.";
	Employees[7582] = "John A.";
	Employees[5328] = "Peter Q.";

	cout << "Employees[3374] = " << Employees[3374] << endl;
	cout << "Map size: " << Employees.size() << endl;

	for (map<int, string>::iterator ii = Employees.begin(); ii != Employees.end(); ++ii)
	{
		cout << ii->first << ": " << ii->second << endl;
	}

	map<string, int> Employeestr;
	// Assignment using array index notation
	Employeestr["Mike C."] = 5234;
	Employeestr["Charlie M."] = 3374;

	// Assignment using member function insert() and STL pair

	Employeestr.insert(std::pair<string, int>("David D.", 1923));

	// Assignment using member function insert() and "value_type()"

	Employeestr.insert(map<string, int>::value_type("John A.", 7582));

	// Assignment using member function insert() and "make_pair()"
	Employeestr.insert(make_pair("Peter Q.", 5328));

	cout << "Map size: " << Employeestr.size() << endl;

	for (map<string, int>::iterator ii = Employeestr.begin(); ii != Employeestr.end(); ++ii)
	{
		cout << ii->first << ": " << ii->second << endl;
	}
	
}