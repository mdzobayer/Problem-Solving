#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);

    int test, t;
    string s, url, cPage;

    cin >> test;
    cin.ignore();
    for (t = 1; t <= test; ++t) {
        cout << "Case " << t << ":\n";
        cPage = "http://www.lightoj.com/";
        stack < string > forwardS, backwardS;

        while(cin >> s) {
            if (s == "VISIT") {
                cin >> url;
                cin.ignore();
                backwardS.push(cPage);
                cPage = url;
                forwardS = stack < string > ();

                cout << url << endl;
            }
            else if (s == "FORWARD") {
                cin.ignore();
                if (forwardS.empty()) {
                    cout << "Ignored" << endl;
                }
                else {
                    backwardS.push(cPage);
                    cPage = forwardS.top();
                    forwardS.pop();
                    cout << cPage << endl;
                }
            }
            else if (s == "BACK") {
                cin.ignore();
                if (backwardS.empty()) {
                    cout << "Ignored" << endl;
                }
                else {
                    forwardS.push(cPage);
                    cPage = backwardS.top();
                    backwardS.pop();
                    cout << cPage << endl;
                }
            }
            else if (s == "QUIT") {
                break;
            }
        }
    }

    return (0);
}
