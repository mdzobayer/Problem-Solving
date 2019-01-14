#include <bits/stdc++.h>
using namespace std;

/// Read & Write to File Short-Cut
#define fRead(x) freopen(x, "r", stdin)
#define fWrite(x) freopen(x, "w", stdout)
/// Data type Short-Cut
#define LLI long long int
#define ULL unsigned long long int
#define ff first
#define ss second
#define mk make_pair
#define phb push_back
#define ppb pop_back
#define phf push_front
#define ppf pop_front
/// Input Short-Cut
#define scan(a) scanf("%d", &a);
#define scan2(a, b) scanf("%d %d", &a, &b);
#define scan3(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define scan4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d);
/// Utility
#define SQR(x) ((x) * (x))
#define PI acos(-1.0)
/// Fast Read and de-active buffer flash
#define FastRead std::cin.sync_with_stdio(false);std::cin.tie(nullptr);

///======================== Let's GO ========================

int main() {

    FastRead

    //fRead("in.txt");

    map <string, int> mp;
    vector< pair <string, int> > vt;
    int n, i;
    string s, temp;
    while(cin >> n) {
        getline(cin,s);
        mp.clear();
        vt.clear();
        for (i = 0; i < n; ++i) {
            getline(cin, s);
            stringstream ss(s);
            ss >> temp;
            //cout << s << endl;
            if (mp.find(temp) != mp.end()) {
                mp[temp] += 1;
            }
            else {
                mp[temp] = 1;
            }
        }
        map<string, int>::iterator it;
        for (it = mp.begin(); it != mp.end(); ++it) {
            vt.phb(mk(it->first, it->second));
        }
        sort(vt.begin(), vt.end());
        for (i = 0; i < vt.size(); ++i) {
            printf("%s %d\n", vt[i].first.c_str(), vt[i].second);
        }
    }

    return (0);
}
