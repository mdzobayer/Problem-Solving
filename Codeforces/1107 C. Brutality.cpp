#include <bits/stdc++.h>
using namespace std;

long long int arr[200000+5];
string s;

class Pair {
public:

};

vector < pair <  int, long long int > > vp;

int main() {

    int n, k, i, len;
    scanf("%d %d", &n, &k);
    for (i = 0; i < n; ++i) {
        scanf("%I64d", &arr[i]);
    }
    cin.ignore();
    cin >> s;
    cerr << s << endl;

    len = 1;
    vp.push_back(make_pair(len, arr[0]));

    for (i = 1; i < n; ++i) {
        if(s[i] == s[i-1])
            vp.push_back(make_pair(len, arr[i]));
        else
            vp.push_back(make_pair( ++len, arr[i]));
    }

    sort(vp.begin(), vp.end());
    for (i = 0; i <= 200000; ++i) {
        arr[i] = k;
    }

    unsigned long long int sum = 0;
    sum += vp.back().second;
    int tch, ch = vp.back().first;
    --arr[ch];
    //cout << vp.back().first << " " << vp.back().second << endl;

    for (i = vp.size() - 2; i >= 0; --i) {
        //cout << vp[i].first << " " << vp[i].second << endl;
        ch = vp[i].first;
        tch = vp[i + 1].first;
        if(ch == tch && arr[ch] > 0) {
            sum += vp[i].second;
            arr[ch]--;
        }
        else if(ch != tch) {
            arr[tch] = k;
            sum += vp[i].second;
            arr[ch]--;
        }
    }
    cout << sum << endl;

    return (0);
}
