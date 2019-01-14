#pragma once
#include <iostream>

using namespace std;

class DisplayAggregation
{
public:
	DisplayAggregation(int sz)
		: size{ sz }
	{
		// Display constructor
	}

	~DisplayAggregation() = default;    // implementing if required

	void DisplayDisplay() const
	{
		cout << "Display attributes: Size " << size << " inches" << endl;
	}

private:
	int size;
	// other display attributes
};
