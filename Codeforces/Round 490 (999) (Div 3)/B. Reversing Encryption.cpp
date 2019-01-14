//#include <bits/stdc++.h>
//
//
//using namespace std;
//
//
//int main() {
//
//    int n, i, x, j;
//    string s, tmp;
//    vector < int > vt;
//    cin >> n;
//    cin.ignore();
//    cin >> s;
//    for (i = n; i > 0; --i) {
//        x = n % i;
//        if (x == 0)
//            vt.push_back(i);
//    }
//    cout << vt.size() << endl;
//    for (i = 0; i < vt.size(); ++i) {
//        x = vt[i];
//        cout << x << endl;
//        tmp = "";
//        for (j = x - 1; j >= 0; --j) {
//            tmp += s[j];
//        }
//        for (j = x; j < s.size(); ++j) {
//            tmp += s[j];
//        }
//        cout << tmp << endl;
//        s = tmp;
//    }
//    cout << s << endl;
//
//    return (0);
//}
#include <bits/stdc++.h>


using namespace std;


int main() {

    int n, i, x, j;
    string s, tmp;
    vector < int > vt;
    cin >> n;
    cin.ignore();
    cin >> s;
    for (i = n; i > 0; --i) {
        x = n % i;
        if (x == 0)
            vt.push_back(i);
    }
    //cout << vt.size() << endl;
    for (i = vt.size() - 1; i >= 0; --i) {
        x = vt[i];
        tmp = "";
        for (j = x - 1; j >= 0; --j) {
            tmp += s[j];
        }
        for (j = x; j < s.size(); ++j) {
            tmp += s[j];
        }
        //cout << tmp << endl;
        s = tmp;
    }
    cout << s << endl;

    return (0);
}
