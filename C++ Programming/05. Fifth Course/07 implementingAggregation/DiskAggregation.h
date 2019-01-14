#pragma once
#include <iostream>

using namespace std;

class DiskAggregation
{
public:
	DiskAggregation(int szGb)
		: sizeGb{ szGb }
	{
		// Disk constructor
	}

	~DiskAggregation() = default;   // implement if required

	void DisplayDisk() const
	{
		cout << "Disk attributes: Size " << sizeGb << "GB" << endl;
	}

private:
	int sizeGb;
	// other Disk attributes

};

