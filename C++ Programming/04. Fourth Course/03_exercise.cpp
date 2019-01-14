/*
    calc <num 1> op <num 2>
        returns the operation on the two numbers

*/

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {

    if (argc != 4) {
        cerr << "Error: invalid number of arguments, must be 4"
             << endl;
        return (1);
    }

    double lhs = stod(argv[1]);
    string op = argv[2];
    double rhs = stod(argv[3]);

    if (op == "+") {
        cout << "Result = " << lhs + rhs << endl;
    }
    else if (op == "-"){
        cout << "Result = " << lhs - rhs << endl;
    }
    else if (op == "x") {
        cout << "Result = " << lhs * rhs << endl;
    }
    else if (op == "/") {
        cout << "Result = " << lhs / rhs << endl;
    }
    else if (op == "^") {
        cout << "Result = " << pow(lhs,rhs) << endl;
    }
    else {
        cerr << "Error: op " << op << " not supported." << endl;
        return (1);
    }

    return (0);
}
