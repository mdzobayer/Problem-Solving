#pragma once
#include <iostream>
using namespace std;

class PrinterAggregation
{
public:
	PrinterAggregation(bool scan, bool fax, bool color)
		: scanner{ scan }, faxMachine{ fax }, colour{ color }
	{
		// printer constructor
	}

	~PrinterAggregation() = default;    // implementing if required

	void DisplayPrinter() const
	{
		cout << "Printer attributes: ";
		if (scanner)
		{
			cout << "Scans ";
		}
		if (faxMachine)
		{
			cout << "Faxes ";
		}
		if (colour)
		{
			cout << "Prints in colour " << endl;
		}
		else
		{
			cout << "Prints in monochrome " << endl;
		}
	}

private:
	bool scanner;
	bool faxMachine;
	bool colour;
	// other printer attributes
};

