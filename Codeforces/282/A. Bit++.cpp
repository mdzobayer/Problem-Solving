#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, i, value = 0;
    string statement;
    cin >> n;
    cin.ignore();
    
    for(i = 0; i < n; ++i) {
        cin >> statement;

        if (statement == "++X" || statement == "X++") 
            ++value;
        else --value; 
    }
    cout << value << endl;

    return (0);
}