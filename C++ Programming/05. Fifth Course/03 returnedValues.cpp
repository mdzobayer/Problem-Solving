#include <iostream>
#include <tuple>

using namespace std;

// Return fundamental data type via return statement
int Sum (int n1, int n2) {
    int temp = n1 + n2;
    return (temp);
    //return n1 + n2;
}
// Return fundamental data type via reference parameter
void Sum2(int n1, int n2, int& total) {
    total = n1 + n2;
}

struct SumAvgRet{
    int sum;
    double avg;
};
// Return complex data type (structure) via return statement
SumAvgRet SumAvg(int n1, int n2) {
    SumAvgRet temp;
    temp.sum = n1 + n2;
    temp.avg = (n1 + n2) / 2.0;
    return (temp);
    //------ Via Universal Initialization -------
    //----- Short Time Version of the Same Code -----
    //return SumAvgRet{ (n1 + n2), (n1 + n2) / 2.0};
    //return { n1 + n2,(n1 + n2) / 2.0};
}
/*
Return type tuple is a template function. The
template can take any number of parameter
*/
// Return std::tuple via return statement - declaration
tuple<int, string, double>SumAvgTuple(int n1, string name, int n2) {
    return make_tuple(n1 + n2, name, (n1 + n2) / 2.0);
}
//Return reference via return statement
int& Sum(int n1, int n2)
{
    int temp = n1 + n2;
    return temp;
    /*
    Not allowed to return reference to a
    temp or local variable
    */
}
//Return reference via return statement
int& Increment(int n1)
{
    return ++n1;
    /*
    Not Allowed because n1 is passed by value,
    and is, therefore a local or temp variable
    */
}
int& Increment(int& n1)
{
    return ++n1;
    //Ok, n1 is a reference, not a local variable
}
int& Increment(const int& n1)
{
    return ++n1;
    /*
    Will not compile because we are
    trying to modify a constant n1
    */
}
//explicitly said return type an int
//auto Sum (int n1, int n2) ->int
//deduce the return type based on an expression
//auto Sum (int n1, int n2) ->decltype(n1+n2)
template <typename T, typename U>
auto Sum (T n1, U n2) ->decltype(n1+n2)
{
    return (n1 + n2);
}
int main() {

    tuple<int, string, double> result;

    result = SumAvgTuple(10,"Zobayer", 15);
    cout << "Sum: " << get<0>(result) << ", "
         << "Name: " << get<1>(result) << ", "
         << "Average: " << get<2>(result) << endl;

    int num1 = 10;
    int num2 = 20;

    auto w = Sum(num1, num2);
    cout << w << endl;
    double x = Sum(10.5, 33.3);
    cout << x << endl;
    auto y = Sum('A', 1);
    cout << (char)y << endl;

    return (0);
};
