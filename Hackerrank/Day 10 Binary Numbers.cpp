#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int maxSo = 0, curr = 0;
    while(n > 0) {
        //cout << "n is " << n << endl;
        if((n & 1) == 0) {
            maxSo = max(maxSo, curr);
            curr = 0;
            //cout << "Debug" << endl;
        }
        else ++curr;

        n >>= 1;
    }
    maxSo = max (maxSo, curr);

    cout << maxSo << endl;
    return (0);
}
