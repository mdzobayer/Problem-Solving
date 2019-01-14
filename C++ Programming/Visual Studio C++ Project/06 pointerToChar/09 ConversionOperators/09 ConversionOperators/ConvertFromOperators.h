#pragma once
#include <iostream>
using namespace std;

class ConvertFromOperators
{
public:
	ConvertFromOperators() = default;

	~ConvertFromOperators() = default;

	operator double() const
	{
		return dValue;
	}

	explicit operator int() const
	{
		return static_cast<int>(dValue);
	}

	operator ConvertFromOperators*()
	{
		return this;
	}

	operator const char*() const
	{
		return "Class ConvertFromOperators";
	}

	void Display() const
	{
		cout << "ConvertFromOpertors::Display()" << endl;
	}

private:
	double dValue = 999.99;
};
