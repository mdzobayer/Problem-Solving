#include <iostream>
using namespace std;
int main(){

    double balance, rate;
    int years, count;
    cout << "What is the annual starting balance ? ";
    cin >> balance;
    cout << "What is the annual interest rate ? ";
    cin >> rate;
    cout << "How many years to calculate interest ? ";
    cin >> years;
    count = 1;
    while (count <= years){
        balance *= rate; //rate 1.xx
        cout << count << ": " << balance << endl;
        ++count;
    }
    cout << "After " << years << " years, your balance will be "
         << balance << "." << endl;

    return (0);
};
