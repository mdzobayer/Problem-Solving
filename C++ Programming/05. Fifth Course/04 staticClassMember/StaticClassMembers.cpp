#include <iostream>
#include "EmployeeStatic.h"
#include "PersonStatic.h"

using namespace std;
int counter()
{
    // local scope (visibility), static persistence (lifetime)
    static int count;
    ++count;
    return count;
}
int main()
{
    for (int x = 0; x < 5; ++x)
    {
        cout << counter() << '\t';
    }
    cout << endl;

    // The following lines demonstrate static class members used to create unique variable
    cout << "Unique employee numbers" << endl;
    EmployeeStatic me;
    EmployeeStatic you;

    cout << me.GetEmpNo() << endl;
    cout << you.GetEmpNo() << endl;
    // The following lines demonstrate static class members used for resource counting
    cout << "Resource Counting" << endl;
    cout << PersonStatic::GetNumPeople() << endl;
    PersonStatic him;
    cout << him.GetNumPeople() << endl;
    PersonStatic *her = new PersonStatic;
    cout << PersonStatic::GetNumPeople() << endl;
    delete her;
    cout << PersonStatic::GetNumPeople() << endl;

    return 0;
}
