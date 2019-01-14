#include <iostream>

using namespace std;
void Reference() {
    int x;
    //int& refx = x; // reference Must be initialized by assignment on declaration
    int& refx{ x }; // or using universal initialization on declaration
                    // a reference cannot be changed
    x = 10;
    refx = 20;      // refx - a reference to x is an alias for x

    int y;
    int* pint;      // pint is a pointer to an int - does not require initialization
    pint = &x;      // pint can point to any int - x
    pint = &y;      // or y

    y = 20;
    *pint = 20;     // pointer must be dereferenced for their value to be used
}
void sumAvgMinMax1(int n1, int n2, int& sum, double& avg, int& min, int& max){
    sum = n1 + n2;
    avg = (n1 + n2) /  2.0;
    min = (n1 < n2) ? n1 : n2;
    max = (n1 > n2) ? n1 : n2;
}
void sumAvgMinMax2(const int& n1, const int& n2, int& sum, double& avg, int& min, int& max) {
    sum = n1 + n2;
    avg = (n1 + n2) /  2.0;
    min = (n1 < n2) ? n1 : n2;
    max = (n1 > n2) ? n1 : n2;
    n1 = 999;
}
void sumAvgMinMax3(int n1, int n2, int& sum, double& avg, int& min, int& max) const {
    sum = n1 + n2;
    avg = (n1 + n2) /  2.0;
    min = (n1 < n2) ? n1 : n2;
    max = (n1 > n2) ? n1 : n2;
}

int main() {
    int num1{ 22 };
    int num2{ 33 };
    int total{ 0 };
    double average{ 0.0 };
    int smaller{ 0 };
    int larger{ 0 };

    sumAvgMinMax1(num1, num2, total, average, smaller, larger);
    sumAvgMinMax2(num1, num2, total, average, smaller, larger);
    sumAvgMinMax3(num1, num2, total, average, smaller, larger);

    return (0);
}
