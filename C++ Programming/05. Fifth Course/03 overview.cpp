#include <iostream>

using namespace std;

int Add (int number1, int number2);

int main() {
    int x{ 10 };
    int y{ 20 };
    int answer{ Add(x,y) };

    //answer = ;

    return (0);
}
int Add (int num1, int num2) {
    int result{ (num1 + num2) };
    return (result);
}
