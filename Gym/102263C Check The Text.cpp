#include <bits/stdc++.h>

using namespace std;

int main() {

    //freopen("in.txt", "r", stdin);

    int n, m, len, i;
    string target, keystroke, current = "";
    bool capsLockStatus = false;

    cin >> n;
    cin.ignore();
    getline(cin, target);
    cin >> m;
    for (i = 0; i < m; ++i) {
        cin >> keystroke;

        if (keystroke == "CapsLock") {
            capsLockStatus = !capsLockStatus;
        }
        else if (keystroke == "Backspace") {
            len = current.size();
            if (len > 0) {
                current.erase(len - 1);
            }
        }
        else if (keystroke == "Space") {
            current += " ";
        }
        else if (keystroke.size() == 1){
            if (capsLockStatus) {
                keystroke[0] = toupper(keystroke[0]);
            }
            current += keystroke;
        }
    }
    //cout << current << endl;
    if (current == target) {
        cout << "Correct" << endl;
    }
    else {
        cout << "Incorrect" << endl;
    }

    return (0);
}