#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

map<string, long long int> database;

int main() {

    ios::sync_with_stdio(false);

    string name;
    long long int i, n, j;

    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> name;
        if (database.count(name) == 0) {
            cout << "OK" << endl;
            database[name] = 1;
        }
        else {
            cout << name << database[name] << endl;
            database[name] += 1;
        }
    }


    return (0);
}
