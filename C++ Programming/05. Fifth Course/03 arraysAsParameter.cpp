#include <iostream>

using namespace std;
void doSomeThings(int nums[]) {
    nums[7] = 9999;
}
//Sum function with sized array[5]
int Sum(int numbs[5]) {
    int total = 0;
    for (int x = 0; x < 5; ++x) {
        total += numbs[x];
    }
    return (total);
}
/*
Sum function with sized array[10]
This is not allowed as you cannot
overload on array size
*/
int Sum(int numbs[10]) {
    int total = 0;
    for (int x = 0; x < 10; ++x) {
        total += numbs[x];
    }
    return (total);
}
//Sum function with unsized sized array
int Sum(int nums[]) {
    int total = 0;
    for (int x = 0; x < ?; ++x) { // How many iteration?
        total += nums[x];
    }
    return (total);
}
// Sum function with unsized array & size parameter
int Sum(int nums[], int size) {
    int total = 0;
    for (int x = 0; x < size; ++x) {
        total += nums[x];
    }
    return (total);
}
// Sum function with unsized array & begin / end parameters
int Sum(int nums[], int begin, int end) {
    int total = 0;
    for (int x = begin; x <= end; ++x) {
        total += nums[x];
    }
    return (total);
}
int main() {

    int numbers[] = {1,2,3,4,5,6,7,8,9,10};
    /*
    Numbers is short form of pointer. Its
    points the first element of the array
    */

    doSomeThings(numbers);
    cout << numbers[6] << endl;
    cout << numbers[7] << endl;
    cout << numbers[8] << endl;
    /*
    Array does n't passed to function by
    value. It passed by reference
    */

    return (0);
}
