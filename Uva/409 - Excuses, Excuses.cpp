#include <bits/stdc++.h>

using namespace std;

int k, e, record[25];
string str[25], s, keyword[25];

bool findKey(const string & key) {
    int i;
    for (i = 0; i < k; ++i) {
        if (keyword[i] == key)
            return true;
    }
    return false;
}


int main() {
    //freopen("in.txt", "r", stdin);

    int i, j, mx, test = 0;

    while(cin >> k >> e) {
        //cout << "k = " << k << " e = " << e << endl;
        cin.ignore();
        ++test;

        for (i = 0; i < k; ++i) {
            cin >> keyword[i];
            //cout << keyword[i] << endl;
            for (j = 0; keyword[i][j]; ++j) {
                keyword[i][j] = tolower(keyword[i][j]);
            }
        }
        cin.ignore();

        for (i = 0; i < e; ++i) {
            getline(cin, str[i]);

            record[i] = 0;
            s = "";
            for (j = 0; str[i][j]; ++j) {
                if (isalpha(str[i][j])) {
                    s += tolower(str[i][j]);
                }
                else {
                    s += ' ';
                }
            }
            //cout << "--- " << str[i] << endl << s << endl;
            stringstream ss(s);

            while(ss >> s) {
                if (findKey(s))
                    ++record[i];
            }
        }
        mx = record[0];
        for (i = 1; i < e; ++i) {
            if (mx < record[i])
                mx = record[i];
        }
        printf("Excuse Set #%d\n", test);
        for (i = 0; i < e; ++i) {
            if (record[i] == mx)
                printf("%s\n", str[i].c_str());
        }
        puts("");
    }

    return (0);
}
