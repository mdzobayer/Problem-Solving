#include <iostream>
using namespace std;
int main()
{
    long long int num;
    while((cin >> num) && (num >= 0)) {
        cout << ((num * num) + num + 2) / 2 << endl;
    }

    return (0);
}
