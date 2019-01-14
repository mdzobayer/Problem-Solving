#pragma once
#include <iostream>
using namespace std;

#include "DiskAggregation.h"
#include "DisplayAggregation.h"
#include "PrinterAggregation.h"

class PCInheritance
	: public DiskAggregation, public DisplayAggregation, public PrinterAggregation
{
public:
	PCInheritance(int diskGb, int screenSize, bool scan, bool fax, bool color)
		: DiskAggregation(diskGb), DisplayAggregation(screenSize),
		PrinterAggregation(scan, fax, color)
	{
		// PC constructor delegates constructor of disk, screen & printer to
		// to objects.
	}

	~PCInheritance() = default;

	void PCDisplay() const
	{
		cout << "PC Attributes: " << endl;
		DiskAggregation::DisplayDisk();
		DisplayAggregation::DisplayDisplay();
		PrinterAggregation::DisplayPrinter();
	}
};

