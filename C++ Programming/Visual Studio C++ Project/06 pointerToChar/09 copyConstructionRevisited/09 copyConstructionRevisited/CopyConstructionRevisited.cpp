#include <iostream>
#include <vector>
using namespace std;
#include "PersonCCRevisited.h"

int main() {

	PersonCC me1("Simon");
	PersonCC clone1("Simon");

	cout << me1.GetName() << endl;
	cout << clone1.GetName() << endl;

	PersonCC me2("Simon");
	PersonCC clone2(me2);

	cout << me2.GetName() << endl;
	cout << clone2.GetName() << endl;

	PersonCC me3("Siom");
	PersonCC clone3 = me3;

	cout << me3.GetName() << endl;
	cout << clone3.GetName() << endl;

	vector<PersonCC> people(3);		// create vector of poeple with 3 elements
	people.push_back(me3);			// push me4 onto the end of the vector

	PersonCC him1("Fred Flintstone");
	PersonCC him2;

	him2 = him1;

	return (0);
}
