
#include "EmployeeExplicit.h"
#include "PersonExplicit.h"

void DoSomething(PersonExplicit p)
{
    // do something
}

int main() {

    EmployeeExplicit Fred("Fred Flintstone", 30, gender::Male, 1234);
    PersonExplicit MrFlinstone(Fred); // Conversion constructor

    //---- Explicit Conversion Constructor -----
    DoSomething((PersonExplicit)Fred);

    return (0);
}
