#include <iostream>
#include <set>

using namespace std;

set <string> mysetA, mysetC, mysetB;

int main() {

    string s;
    int t, i, test, n, m;
    cin >> test;
    //cin.ignore();
    for (t = 1; t <= test; ++t) {
        cin >> n >> m;
        //cerr << "n is " << n << " m is " << m << endl;
        cin.ignore();

        mysetA.clear();
        mysetC.clear();
        mysetB.clear();

        for (i = 0; i < n; ++i) {
            getline(cin, s);
            mysetA.insert(s);
        }
        for (i = 0; i < m; ++i) {
             getline(cin, s);
            mysetB.insert(s);
        }
        set<string>::iterator it, jt;
        for (it = mysetA.begin(); it != mysetA.end(); ++it) {
            for (jt = mysetB.begin(); jt != mysetB.end(); ++jt) {
                mysetC.insert(*it + *jt);
            }
        }
        cout << "Case " << t << ": " << mysetC.size() << endl;
    }

    return (0);
}
