#include <iostream>
#include "EmployeeOverview.h"

using namespace std;

int main()
{
    Employee worker;    // default constructor called
    //------ Overloaded Constructor Called -------
    Employee worker1("Fred Flintstone", 1234, 1234);
    // Narrowing conversion not allow on universal initialization
    Employee worker2{"Zobayer Mahmud", 1234, 1234};

    cout << worker.GetName() << " "
         << worker.GetEmpNo() << " "
         << worker.GetExtension() << endl;
    cout << worker1.GetName() << " "
         << worker1.GetEmpNo() << " "
         << worker1.GetExtension() << endl;
    cout << worker2.GetName() << " "
         << worker2.GetEmpNo() << " "
         << worker2.GetExtension() << endl;

    return 0;
}
