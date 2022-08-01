#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, loop, first, second;
    cin >> n;

    if (n == 2 || n == 3) {
        cout << "NO SOLUTION" << endl;
        return (0);
    }
    else if (n == 1) {
        cout << "1" << endl;
        return (0);
    }
    else if (n == 4) {
        cout << "3 1 4 2" << endl;
        return (0);
    }

    if (n % 2 == 0) {
        loop = n / 2;
        -- loop;
        
        first = (n / 2) + 1;
        second = 2;
    }
    else {
        loop = n / 2;
    

        first = (n / 2) + 2;
        second = 2;
    }

    while(loop > 0) {

        cout << first << " " << second << " ";

        first ++;
        second ++;

        --loop;
    }

    if (n % 2 == 0) {
        cout << first << " 1" << endl; 
    }
    else {
        cout << 1 << endl;
    }

    return (0);
}