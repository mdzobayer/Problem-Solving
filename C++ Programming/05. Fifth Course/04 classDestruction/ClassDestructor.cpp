#include "PersonDestructor.h"

void DoSomethingWithPerson(PersonDestructor p)
{
    p.UsePerson();
    // p goes out of scope and gets destroyed here
}

void CreateAndUsePerson()
{
    PersonDestructor p2;
    p2.UsePerson();
    // p2 goes out of scope and gets destroyed here
}

int main() {
    PersonDestructor *p3 = new PersonDestructor;
    p3->UsePerson();

    delete p3;
    // p3 goes out of scope and gets destroyed here

    return (0);
}
