#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

void forwardPrint(int x) {

    if (x > 10)
        return ;
    printf("%d\n", 10 - x);
    forwardPrint(x + 1);

    printf("%d\n", abs(x - 10));

}
void print(vector<int> &v) {
    for (int i = 0; i < v.size(); ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
}
void combination(int arr[], int st, int k, vector<int> &vt) {
    if (k == 0) {
        /// Print and return
        print(vt);
        return;
    }
    vt.push_back(arr[st]);
    combination(arr, st + 1, k - 1, vt);
    vt.pop_back();
    combination(arr, st + 1, k - 1, vt);
}

int main() {
    vector<int> v;
    forwardPrint(0);
    int arr[] = {1, 2, 3};
    combination(arr, 0, 3, v);


    return (0);
}
