#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector<int> Z_Algorithm(string s) {
    vector<int> z(s.size() + 1);
    z[0] = 0;
    int k = 0, left = 0, right = 0, k1;
    for (k = 1; k < s.size(); ++k) {
        if (k > right) {
            left = right = k;
            while(right < s.size() && s[right] == s[right - left]) {
                ++right;
            }
            z[k] = right - left;
            --right;
        }
        else {
            k1 = k - left;
            if (z[k] < right - k + 1) {
                z[k] = z[k1];
            }
            else {
                left = k;
                while(right < s.size() && s[right] == s[right - left]) {
                    ++right;
                }
                z[k] = right - left;
                --right;
            }
        }
    }
    return z;
}

int main() {

    string text = "abaxabab";
    string pattern = "aba";

    string z = pattern + '$' + text;

    vector<int> zarr = Z_Algorithm(z);
    for (int i = 0; i < zarr.size(); ++i) {
        if (zarr[i] == pattern.size()) {
            printf("Pattern index are %d.\n", i - pattern.size());
        }
    }


    return (0);
}
