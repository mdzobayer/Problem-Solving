#include <iostream>
using namespace std;
int main(){
    double balance, rate;
    int years, target;
    years = 0;
    cout << "What is the beginning balance ?";
    cin >> balance;
    cout << "What is the annual interest rate ?";
    cin >> rate;
    cout << "What is the target balance ?";
    cin >> target;
    while (balance < target){
        balance *= rate;
        ++years;
    };
    cout << "It will take " << years
         << " years to reach the target balance "
         << "of " << target << "." << endl;

    return (0);
};
