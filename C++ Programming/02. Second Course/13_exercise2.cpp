#include <iostream>

using namespace std;
class Calculator{
public:
    double add(double op1, double op2){
        return op1 + op2;
    };
    double sub(double op1, double op2){
        return op1 - op2;
    }
    double mult(double op1, double op2){
        return op1 * op2;
    };
    double div(double op1, double op2){
        return op1 / op2;
    };

    double calc(double op1, double op2, char op){
        if(op == '+')
            return add(op1,op2);
        else if(op == '-')
            return sub(op1 , op2);
        else if(op == '*')
            return mult(op1 , op2);
        else if(op == '/')
            return div(op1 , op2);
    }

};
int main(){
    class Calculator c;
    double op1, op2;
    char op;
    while(true){
        cout << "> ";
        cin >> op1 >> op >> op2;
        cout << "\033 = " << c.calc(op1,op2,op) << endl;
    }
    return (0);
};
