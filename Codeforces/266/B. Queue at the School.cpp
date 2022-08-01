#include <bits/stdc++.h>

using namespace std;

void swapChar(char &a, char &b) {
    char c = a;
    a = b;
    b = c; 
}

int main() {

    int n, time, i, operation;
    char str[55];
    cin >> n >> time;
    cin.ignore();
    cin >> str;

    for (int j = 0; j < time; ++j) {
        for (i = 1; i < n; ++i) {
            if (str[i-1] == 'B' && str[i] == 'G') {
                swapChar(str[i - 1], str[i]);
                ++i;
            }
        }
    }
    
    cout << str << endl;

    return (0);
}