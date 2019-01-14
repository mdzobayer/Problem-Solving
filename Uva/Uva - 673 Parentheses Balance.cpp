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


char isBalance(char c) {
    if (c == ')') return '(';
    else if (c == ']') return '[';
}

int main() {

    //freopen("in.txt", "r", stdin);

    int test, i, len;
    char str[150];
    bool flag;
    vector<char> st;
    scanf("%d", &test);
    getchar();

    while(test--) {
        st.clear();
        flag = true;
        gets(str);
        len = strlen(str);
        for (i = 0; i < len; ++i) {
            if (str[i] == '(') {
                st.phb('(');
            }
            else if (str[i] == '[') {
                st.phb('[');
            }
            else if (str[i] == ')') {
                if (st.empty()) {
                    flag = false;
                    break;
                }
                if (st.back() == isBalance(str[i])) {
                    st.ppb();
                }
                else {
                    flag = false;
                    break;
                }
            }
            else if (str[i] == ']') {
                if (st.empty()) {
                    flag = false;
                    break;
                }
                //cout << st.back() << " " << isBalance(str[i]) << endl;
                if (st.back() == isBalance(str[i])) {
                    st.ppb();
                }
                else {
                    flag = false;
                    break;
                };
            }
        }
        if (flag && st.empty())
            printf("Yes\n");
        else
            printf("No\n");
    }

    return (0);
}
