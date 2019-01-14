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
/// C Style Input Short-Cut
#define scan(a) scanf("%d", &a);
#define scan2(a, b) scanf("%d %d", &a, &b);
#define scan3(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define scan4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d);
/// Utility
#define SWAP(a, b) a = a ^ b, b = a ^ b, a = a ^ b;
#define SQR(x) ((x) * (x))
#define PI acos(-1.0)
/// Fast Read and de-active buffer flash for C++
#define FastRead std::cin.sync_with_stdio(false);std::cin.tie(nullptr);

///======================== Let's GO ========================
ULL findRoot(ULL root[], ULL curr){
    if (root[curr] == curr) return curr;
    else
        return root[curr] = findRoot(root, root[curr]);
}
int main() {
    FastRead

    fRead("in.txt");
    //fWrite("out.txt");

    string s1, s2;
    ULL root[100000+10], Rank[100000+10], id;
    map<string, ULL> network;
    ULL test, f, i;
    cin >> test;
    //cout << "After test input" << endl;
    while(test--) {
        network.clear();

        for (id = 0; id < 100005; ++id) {
            root[id] = id;
            Rank[id] = 0;
            //cout << "In a loop" << endl;
        }
        id = 0;
        cin >> f;
        //cout << "After taking F" << endl;
        for (i = 0; i < f; ++i) {
            cin.ignore();
            cin >> s1;
            cin >> s2;
            if((network.find(s1) == network.end()) && (network.find(s2) == network.end())){

                if (s1 == s2){
                    network[s2] = id;
                    Rank[id] = 1;
                }
                else{
                    network[s1] = id;
                    network[s2] = id;
                    Rank[id] = 2;
                }

                cout << Rank[id] << endl;
                ++id;
            }
            else if((network.find(s1) != network.end()) && (network.find(s2) != network.end())){


                network[s1] = findRoot(root, network[s1]);
                network[s2] = findRoot(root, network[s2]);
                if (network[s1] == network[s2]) {
                    cout << Rank[network[s1]] << " We are already " << s1 << " " << s2 << endl;
                    continue;
                }

                if (Rank[network[s1]] >= Rank[network[s2]]) {
                    Rank[network[s1]] += Rank[network[s2]];

                    root[network[s2]] = root[network[s1]];

                }
                else {
                    Rank[network[s2]] += Rank[network[s1]];
                    root[network[s1]] = root[network[s2]];
                }

                cout << Rank[network[s1]] << endl;
            }
            else if (network.find(s1) != network.end()) {
                //root[network[s1]] += 1;

                network[s1] = findRoot(root, network[s1]);

                network[s2] = network[s1];

                cout << ++Rank[network[s1]] << endl;
            }
            else {
                network[s2] = findRoot(root, network[s2]);

                network[s1] = network[s2];

                cout << ++Rank[network[s1]] << endl;
            }

        }
    }

    return (0);
}
