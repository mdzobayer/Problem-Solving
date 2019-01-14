#include <iostream>
#include <cstddef>

using namespace std;

int main(int argc, char ** argv)
{
    long long int t, a, b;
    cin >> t;
    for (size_t i = 0; i < t; i++) {
        cin >> a >> b;
        if (a > b)
            cout << ">" << endl;
        else if (a < b)
            cout << "<" << endl;
        else
            cout << "=" << endl;
    }
}
