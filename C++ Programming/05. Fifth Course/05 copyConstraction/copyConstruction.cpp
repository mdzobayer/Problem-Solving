#include <iostream>
#include <vector>
using namespace std;
#include "PersonCC.h"

int main() {
    PersonCC me1("Simon");
    PersonCC clone1("Simon");

    cout << me1.GetName() << endl;
    cout << clone1.GetName() << endl;

    PersonCC me2("Simon");
    PersonCC clone2(me2);

    cout << me2.GetName() << endl;
    cout << clone2.GetName() << endl;

    PersonCC me3("Simon");
    PersonCC clone3 = me3;

    cout << me3.GetName() << endl;
    cout << clone3.GetName() << endl;

    // Create vector of people with 3 elements
    vector<PersonCC> people(3);
    // push me4 onto the end of the vector
    people.push_back(me3);

    return (0);
}
