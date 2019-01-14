#include "PersonConversion.h"
#include "PersonConversion.h"
void DoSomething(PersonConversion p) {
    // do something
}
int main() {
    EmployeeConversion Fred ("Fred Flintstone", 30, gender::Male, 1234);
    PersonConversion MrFlintstone(Fred);    // conversion constructor
    //-----Implicit Conversion Constructor------
    DoSomething(Fred);
    return (0);
}
