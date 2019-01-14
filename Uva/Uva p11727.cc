#include <iostream>

using namespace std;

int main()
{
    int t;
    unsigned int num1, num2, num3;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> num1 >> num2 >> num3;
        cout << "Case " << i << ": ";
        if ((num1 < num2) && (num1 > num3)) {
            cout << num1 << endl;
        }
        else if ((num1 > num2) && (num1 < num3)) {
            cout << num1 << endl;
        }
        else if ((num2 < num3) && (num2 > num1)) {
            cout << num2 << endl;
        }
        else if ((num2 > num3) && (num2 < num1)) {
            cout << num2 << endl;
        }
        else {
            cout << num3 << endl;
        }
    }

    return (0);
}
