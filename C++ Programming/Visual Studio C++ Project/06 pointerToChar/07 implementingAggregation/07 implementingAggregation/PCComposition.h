#pragma once
#include <iostream>
#include <vector>
using namespace std;

#include "DiskAggregation.h"
#include "DisplayAggregation.h"
#include "PrinterAggregation.h"

class PCComposition
{
public:

	PCComposition(int diskGb)
	{
		// PC constructor our PC must have at least 1 disk.
		disks.emplace_back(new DiskAggregation(diskGb));
	}

	~PCComposition()
	{
		// since we have custody of these objects delete all disks, displays
		// & printers
		for (unsigned int x = 0; x < disks.size(); ++x)
		{
			delete disks[x];
		}
		for (unsigned int x = 0; x < displays.size(); ++x)
		{
			delete displays[x];
		}
		for (unsigned int x = 0; x < printers.size(); ++x)
		{
			delete printers[x];
		}
	}
	void PCAddDisk(int diskGb)
	{
		// add a disk drive to the vector
		disks.emplace_back(new DiskAggregation(diskGb));
	}

	void PCAddDisplay(int screenSize)
	{
		// add a screen to the vector
		displays.emplace_back(new DisplayAggregation(screenSize));
	}

	void PCAddPrinter(bool scan, bool fax, bool color)
	{
		// add a printer to the vector
		printers.emplace_back(new PrinterAggregation(scan, fax, color));
	}

	// We could / should also add routines to remove disks, screens & printers.
	// However, for brevity this code will be omitted from this example.

	void PCDisplay() const
	{
		// display all disks, screens & printers
		cout << "PC Attributes: " << endl;
		cout << "Disks: " << endl;
		for (unsigned int x = 0; x < disks.size(); ++x)
		{
			disks[x]->DisplayDisk();
		}
		cout << "Display: " << endl;
		for (unsigned int x = 0; x < displays.size(); ++x)
		{
			displays[x]->DisplayDisplay();
		}
		cout << "Printers: " << endl;
		for (unsigned int x = 0; x < printers.size(); ++x)
		{
			printers[x]->DisplayPrinter();
		}
	}

private:
	// dynamic vector to contain any number of disks
	vector<DiskAggregation*> disks;
	// dynamic vector to contain any numbers of displays
	vector<DisplayAggregation*> displays;
	// dynamic vector to contain any numbers of printers
	vector<PrinterAggregation*> printers;
};

