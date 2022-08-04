#include <bits/stdc++.h>

using namespace std;

int AddModulo(int x, int m)
{
    return x + (x % m);
}

void solve()
{

    int n, i;
    cin >> n;
    int arr[n + 5];

    bool flag5 = false;

    for (i = 0; i < n; ++i)
    {
        cin >> arr[i];

        if (arr[i] % 5 == 0)
        {
            flag5 = true;
        }
        arr[i] = AddModulo(arr[i], 10);
    }

    if (flag5)
    {
        for (i = 1; i < n; ++i)
        {
            if (arr[i] != arr[i - 1])
            {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
        return;
    }

    bool flag4 = false, flagOther = false;
    for (i = 0; i < n; ++i) {
        while(arr[i] % 10 != 4) {
            arr[i] = AddModulo(arr[i], 10);
        }

        if (arr[i] % 20 == 4) {
            flag4 = true;
        } else {
            flagOther = true;
        }
    }

    // cout << "arr: ";
    // for (i = 0; i < n; ++i)
    //     {
    //         cout << arr[i] << " ";
    //     }
    // cout << endl;

    if (flag4 && flagOther) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main()
{
    // freopen("in.txt", "r", stdin);

    int test;
    cin >> test;
    while (test--)
    {
        solve();
    }

    return (0);
}