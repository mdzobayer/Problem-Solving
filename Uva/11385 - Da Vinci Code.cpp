#include <bits/stdc++.h>
#define ll long long int

using namespace std;


int keys[100+5];
map < ll, int > fiboIndex;

void genFibo() {
    ll x = 1;
    ll y = 2;
    ll z;

    fiboIndex[x] = 0;
    fiboIndex[y] = 1;

    int i;
    for ( i = 2; y < (ll)2147483648; ++i) {
        z = y + x;
        fiboIndex[z] = i;
        x = y;
        y = z;
    }
}

int main() {
    //freopen("in.txt", "r" ,stdin);
    //freopen("out.txt", "w" ,stdout);

    genFibo();
    int test, n, x, i, j;
    string chiper, encryp;
    cin >> test;
    //cerr << "Debug1" << endl;
    while(test--) {
        cin >> n;
        int mx = INT_MIN;
        for (i = 0; i < n; ++i) {
            cin >> keys[i];
            if (mx < keys[i])
                mx = keys[i];
        }
        cin.ignore();
        getline(cin, chiper);
        encryp = "";
        for (i = 0; i < chiper.size(); ++i) {
            encryp += ' ';
        }
        char output[110];
        memset(output, ' ', sizeof(output));
        x = fiboIndex[mx];
        output[x+1] = 0;
        j = 0;
        for (i = 0; i < n; ++i) {
            while(!isupper(chiper[j]))
                ++j;
            x = fiboIndex[keys[i]];
            //encryp[x] = chiper[j];
            output[x] = chiper[j];
            ++j;
        }
        //cout << encryp << endl;
        cout << output << endl;
    }

    return (0);
}
