#include <bits/stdc++.h>

using namespace std;

int main() {

    int vf, vm, vs, vmas;
    cin >> vf >> vm >> vs >> vmas;

    if (vmas > vs && (2 * vs < vmas)) {
        printf("-1\n");
    }
    else if (vmas > vm && (2 * vm < vmas)) {
        printf("-1\n");
    }
    else if (vmas > vf && (2 * vf < vmas)) {
        printf("-1\n");
    }
    else {
        printf("%d\n%d\n%d\n", vf, vm, vs);
    }




    return (0);
}
