#include <bits/stdc++.h>


using namespace std;

int main() {

    int a, b, c;

    cin >> a >> b >> c;

    if ((a+b) > c) {
        if ((a+c) > b) {
            if((b+c) > a) {
                printf("0\n");
            }
            else {
                cout << min(b,c) - (a + 1) << endl;
            }
        }
        else {
            cout << min(a,c) - (b+1) << endl;
        }
    }
    else cout << min(a,b) - (c+1) << endl;

    return (0);
}
