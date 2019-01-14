#include <iostream>
#include <vector>
using namespace std;
#include "PersonOpEqual.h"

int main() {

	PersonCC him1("Fred Flintstone");
	PersonCC him2;

	/*him2 = him1;*/

	him2.operator=(him1);

	cout << him1.GetName() << endl;
	cout << him2.GetName() << endl;

	return (0);
}