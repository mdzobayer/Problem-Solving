#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int arr[130];

int main() {

    int n, i, j, wrongAns, uniqueChar;
    bool flag;
    string str1, str2;
    while(scanf("%d", &n)) {
        memset(arr, -1, sizeof(arr));
        getchar();
        if (n == -1) break;
        uniqueChar = wrongAns = 0;
        getline(cin, str1);
        getline(cin, str2);
        /// Pre-process first string
        for (i = 0; i < str1.size(); ++i) {
            if (arr[str1[i]] == -1) {
                uniqueChar += 1;
            }
            arr[str1[i]] = 1;
        }
        /// Operation with second string
        for (i = 0; (i < str2.size()) && (wrongAns < 7) && (uniqueChar != 0); ++i) {
            if (arr[str2[i]] == -1) {
                ++wrongAns;
            }
            else if (arr[str2[i]] == 1) {
                --uniqueChar;
                arr[str2[i]] = 0;
            }
            else {
                // Nothing
            }
        }
        printf("Round %d\n", n);
        if (wrongAns >= 7) {
            printf("You lose.\n");
        }
        else if (uniqueChar <= 0) {
            printf("You win.\n");
        }
        else {
            printf("You chickened out.\n");
        }
    }

    return (0);
}
