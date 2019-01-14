#include <iostream>
using namespace std;
#include "ConvertFromOperators.h"

int main() {

	ConvertFromOperators convertFrom;
	double d;
	int i;
	ConvertFromOperators* pConvertFrom;
	char* string = new char[255];

	d = convertFrom;					// implicit conversion to double

	// i = convertFrom;					// implicti conversion to int gives error.

	i = static_cast<int>(convertFrom);	// explicit conversion to int

	pConvertFrom = convertFrom;			// implicit conversion to ConvertFromOperator*
	pConvertFrom->Display();			// pointer used to call Display()

	cout << convertFrom << endl;		// you may expect this code to call the char* conversion. However,
										// it calls the double conversion

	strcpy_s(string, 255, convertFrom);	// implicit conversion to char*
	cout << string << endl;		
	
	delete[] string;

	return (0);
}
