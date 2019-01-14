#include <iostream>
using namespace std;
double calc(double operand1, double operand2, char oper){
    //double result;
    if(oper == '*')
        return (operand1 * operand2);
    else if(oper == '/')
        return (operand1 / operand2);
    else if(oper == '+')
        return (operand1 + operand2);
    else if(oper == '-')
        return (operand1 - operand2);

}
int main(){

    double op1, op2;
    char op, res;
    bool loop = true;

    while (loop){

        cout << "Enter expression: ";
        cin >> op1 >> op >> op2;
        cout << "Result: " << calc(op1,op2,op) << endl;
        cout << "Again or Close (y/n)?: ";
        cin >> res;
        if(res == 'y')
            loop = 1;
        else
            loop = 0;
        //cout << '\n';

    }
    return (0);
}
