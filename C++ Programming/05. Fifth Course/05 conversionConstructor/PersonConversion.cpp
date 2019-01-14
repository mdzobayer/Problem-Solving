#include "PersonConversion.h"

PersonConversion::PersonConversion(char* nam, int ag, char sx)
    : name{ nam }, age{ ag }, sex{ sx } { };

PersonConversion::PersonConversion(const EmployeeConversion& e)
{
    /*
    name = e.name; // won't work because person does not
                    have access to private data member of Employee.
                    could use friend classes, encapsulation.
    */
    name = e.GetName();
    age = e.GetAge();
    switch(e.GetSex())
    {
    case gender::Male:
        sex = 'M';
        break;
    case gender::Female:
        sex = 'F';
        break;
    default:
    {
        sex = '?';
        break;
    }
    }
}
