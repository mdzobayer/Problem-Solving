#include <iostream>

using namespace std;

int main(){
    double operand1, operand2, result;
    char op;
    cout << "Enter an expression (operand1 operator operand2): ";
    cin >> operand1 >> op >> operand2;
    if (op == '*'){
        result = operand1 * operand2;
        cout << "Result: " << result << endl;
    }
    else if (op == '/'){
        result = operand1 / operand2;
        cout << "Result: " << result << endl;
    }
    else if (op == '+'){
        result = operand1 + operand2;
        cout << "Result: " << result << endl;
    }
    else if (op == '-'){
        result = operand1 - operand2;
        cout << "Result: " << result << endl;
    }
    else {
        cout << "Bad Expression. Try again" << endl;
    }

    return (0);

}
