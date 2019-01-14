#include <iostream>

using namespace std;

int main() {

    int c, n, dvd;

    cin >> c;
    for ( unsigned int i = 1; i <= c; i++)
    {
        cin >> n;
        cout << "Case " << i << ":";
        for ( unsigned int j = 1; j <= n; j++)
        {
            if ( n % j == 0){
                cout << " " << j;
            }
        }
        cout << endl;
    }

    return (0);
}
