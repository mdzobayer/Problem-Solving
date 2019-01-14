#include <iostream>

using namespace std;
//explicitly said return type an int
//auto Sum (int n1, int n2) ->int
//deduce the return type based on an expression
//auto Sum (int n1, int n2) ->decltype(n1+n2)
template <typename T, typename U>
auto Sum (T n1, U n2) //->decltype(n1+n2)
{
    return (n1 + n2);
}
int main() {

    int num1 = 10;
    int num2 = 20;

    auto w = Sum(num1, num2);
    cout << w << endl;
    double x = Sum(10.5, 33.3);
    cout << x << endl;
    auto y = Sum('A', 1);
    cout << (char)y << endl;

    return (0);
}
