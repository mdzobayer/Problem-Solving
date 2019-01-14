#include <bits/stdc++.h>

using namespace std;



int main() {

    //freopen("in.txt", "r", stdin);

    int test, t, n, m, i, v;
    string s;
    deque < int > dq;

    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d %d", &n, &m);
        getchar();
        dq.clear();
        printf("Case %d:\n", t);
        for (i = 0; i < m; ++i) {
            cin >> s;
            if (s == "pushLeft") {
                cin >> v;
                if (dq.size() == n) {
                    cout << "The queue is full" << endl;
                }
                else {
                    cout << "Pushed in left: " << v << endl;
                    dq.push_front(v);
                }
            }
            else if (s == "pushRight") {
                cin >> v;
                if (dq.size() == n) {
                    cout << "The queue is full" << endl;
                }
                else {
                    cout << "Pushed in right: " << v << endl;
                    dq.push_back(v);
                }
            }
            else if (s == "popLeft") {
                if (dq.size() <= 0) {
                    cout << "The queue is empty" << endl;
                }
                else {
                    cout << "Popped from left: " << dq.front() << endl;
                    dq.pop_front();
                }
            }
            else if (s == "popRight") {
                if (dq.size() <= 0) {
                    cout << "The queue is empty" << endl;
                }
                else {
                    cout << "Popped from right: " << dq.back() << endl;
                    dq.pop_back();
                }
            }
        }
    }

    return (0);
}
