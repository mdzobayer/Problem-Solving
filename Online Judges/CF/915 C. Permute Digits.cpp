#include <bits/stdc++.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>

using namespace std;

string a, b, maxi;

bool generateSol(bool chk, int remain) {
    if (remain == 0 && maxi.size() == a.size()) return true;
    else if (remain == 0 && maxi.size() != a.size()) return false;

    j = a.size() - 1;
    for ( ; j >= 0; --j) {
        cout << "j is " << j << " taken " << taken[j] << " " << chk << endl;
        if (chk && taken[j]) {
            cout << "I am direct " << endl;
            maxi += a[j];
            ++i;
            taken[j] = false;
            j = a.size();
        }
        else if (b[i] >= a[j] && taken[j]) {
                    //cout << "     In condition " << a[j] << endl;
            maxi += a[j];
            if (b[i] > a[j])
                chk = true;
            ++i;
            taken[j] = false;
            j = a.size();
                    //cout << "re initialize " << j << endl;
        }

    }

    return false;
}

int main() {


    bool taken[30];
    memset(taken, true, sizeof(taken));
    cin >> a;
    cin >> b;
    sort(a.begin(), a.end());

//    if (a < b)
//        maxi = a;
//    else maxi = b;
    cout << a << " " << b << endl;
    //int n = a.size();
//    for (int i = a.size(); i < b.size(); ++i) {
//        a += '0';
//    }
    //cout << a << endl;
    bool chk = false;
    if (a.size() < b.size()) chk = true;
//    while(next_permutation(a.begin(), a.end())) {
//        if ( chk && a >= b) break;
//        maxi = a;
//    }
//    cout << maxi << endl;
    int j, i = 0;
    maxi = "";
    //if (chk) {
       // while(i < a.size()) {
            j = a.size() - 1;
            for ( ; j >= 0; --j) {
                cout << "j is " << j << " taken " << taken[j] << " " << chk << endl;
                if (chk && taken[j]) {
                    cout << "I am direct " << endl;
                    maxi += a[j];
                    ++i;
                    taken[j] = false;
                    j = a.size();
                }
                else if (b[i] >= a[j] && taken[j]) {
                    //cout << "     In condition " << a[j] << endl;
                    maxi += a[j];
                    if (b[i] > a[j])
                        chk = true;
                    ++i;
                    taken[j] = false;
                    j = a.size();
                    //cout << "re initialize " << j << endl;
                }
                else {
                    cout <<
                }


            }
            cout << "ending j is " << j << endl;
            //sleep(500);
        //}
    //}
    cout << maxi << endl;

    return (0);
}
