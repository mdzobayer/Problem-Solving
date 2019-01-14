#include <iostream>
using namespace std;
int main(){
    /*
    double balance, rate;
    int years;
    cout << "What is the beginning balance ? ";
    cin >> balance;
    cout << "What is the interest rate ?";
    cin >> rate;
    cout << "How many years to calculate ?";
    cin >> years;
    for (int i = 1; i <= years; ++i){
        balance *= rate;
    }
    cout << "After " << years << " years, your balance will be "
         << balance << "." << endl;
    */

    int num1, num2, product;
    product = 0;
    cout << "What is the first number ?";
    cin >> num1;
    cout << "What is the second number ?";
    cin >> num2;
    for (int i = 1; i <= num1; ++i){
        product +=num2;
    };
    cout << "Result: " << product << endl;
    return (0);
}
