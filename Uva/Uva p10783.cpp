#include <iostream>
using namespace std;

bool isOdd(int n) {
    if (n % 2 == 1) {
        return true;
    }
    else
        return false;
}

int main()
{
    int t, num1, num2, sum;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        sum = 0;
        cin >> num1 >> num2;
        while(num1 <= num2) {
            if(isOdd(num1)) {
                sum += num1;
            }
            ++num1;
        }
        cout << "Case " << i << ": " << sum << endl;
    }

    return (0);
}
