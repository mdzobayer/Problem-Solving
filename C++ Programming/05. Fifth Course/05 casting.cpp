#include <iostream>

using namespace std;

class Person
{
public:
    //-- Modifier Function --
    void GrowOlder(){
        ++age;
    }
    //-- Query Function --
    int GetAge() const {
        return age;
    }
private:
    int age = 21;
};

void DoSomething(const Person* p) {
    // do something with person
    // p->GrowOder(); // Error! p is a pointer to a const Person. Can't call modifier functions
    // on const object.
    // workround
    Person* nonconst;
    nonconst = const_cast<Person*>(p);
    nonconst->GrowOlder();

    cout << "Value of p and nonconst pointers: " << hex << p << " " << nonconst << endl;
    // both p and nonconst point to the same address (same object) p is const, nonconst is not.
    cout << p->GetAge() << endl;
}
int main() {

    double d = 99.99;
    int x;

    x = d;      // compiler warning, narrowing conversion,implicit cast
    x = (int)d; // C cast supresses warning explicit cast

    double e = 99.99;
    int y;

    y = e;      // compiler warning, narrowing conversion,implicit cast
    y = int(e); // C++ functional cast supresses warning explicit cast

    int a = 123;
    double b = 99.99;
    int* pa = &a;    // pa points to a
    double* pb = &b; // pb points to b

    pa = (int*)a;   // convert a - 123 to a pointer to an int
    pa = (int*)pb;  // convert pb - pointer to a double to pointer to an int

    a = static_cast<int>(b);    // convert b - 99.99 to an int - ERROR, must be pointer to
                                // a class or void pointer
    pa = static_cast<int*>(pb); // convert pb - pointer to a double to pointer to an int
                                // ERROR, must be pointer to a class or void pointer

    a = dynamic_cast<int>(b);   // convert b - 99.99 to an int - ERROR, must be pointer to
                                // a class or void pointer
    pa = dynamic_cast<int*>(pb);// convert pb - pointer to a double to pointer to an int
                                // ERROR, must be pointer to a class or void pointer

    Person* pSomeone = new Person;
    DoSomething(pSomeone);

    return (0);
}
