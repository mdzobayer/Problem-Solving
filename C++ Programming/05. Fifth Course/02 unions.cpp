#include <iostream>

using namespace std;

struct Employee {
    int employee_number;
    float salary;
};
union Memory {
    int int_number;
    float float_number;
    float ch;
};
union Bitfields {
    unsigned char wholebyte;
    struct individualbits {
        unsigned bit0 : 1;
        unsigned bit1 : 1;
        unsigned bit2 : 1;
        unsigned bit3 : 1;
        unsigned bit4 : 1;
        unsigned bit5 : 1;
        unsigned bit6 : 1;
        unsigned bit7 : 1;
    }bits;
};

int main() {

    Memory space;
    cout << endl;
    cout << "Size of Employee struct = " << sizeof(Employee) << endl;
    cout << "Size of Memory union = " << sizeof(Memory) << endl << endl;

    // use space.int_number
    space.int_number = 99;
    cout << "Value of int_number in Memory union = " << space.int_number << endl;
    // use space.float_number
    space.float_number = 33.3333;
    cout << "Value of float_number in Memory union = " << space.float_number << endl;
    // invalid use of space.int_number
    cout << space.int_number << endl << endl;

    space.ch = 6.2;
    //cout << space.ch << endl;
    // invalid use of space.int_number
    cout << space.float_number << endl;
    space.float_number = 555;
    cout << space.int_number << endl;
    cout << space.ch << endl;
    cout << (char)64 << endl;


    // practical use of union in bit manipulation
    Bitfields byte;
    byte.wholebyte = 0;
    byte.bits.bit0 = 1;
    byte.bits.bit3 = 1;
    cout << "value of wholebyte in Bitfields union = " << (int)byte.wholebyte << endl;

    return (0);
}
