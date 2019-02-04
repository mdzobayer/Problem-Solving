#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main() {
    int patt[20], i, j, k;
    string pattern, text;
    pattern = "abcaby";
    //pattern = "aabaabaaa";
    //pattern = "abcdabca";
    text = "abxabcabcabyabcaby";
    patt[0] = 0;
    /// preprocessing array.
    for (i = 1, j = 0, k = 0; i < pattern.size(); ) {
        if (pattern[j] == pattern[i]) {
            patt[++k] = j + 1;
            ++j;
            ++i;
        }
        else if (pattern[j] != pattern[i] && j == 0) {
            patt[++k] = 0;
            ++i;
        }
        else {
            j = patt[j - 1];
        }
    }
    for (j = 0; j < i; ++j) {
        printf("%d ", patt[j]);
    }
    printf("\n");

    /// Pattern Search
    for (i = 0, j = 0, k = 0; i < text.size(); ) {
        if (text[i] == pattern[j]) {
            ++j;
            ++i;
        }
        else if (text[i] != pattern[j] && j == 0) {
            ++i;
            k = i;
        }
        else {
            j = patt[j - 1];
            k += (j+1);
        }

        if( j == pattern.size()) {
        	cout << "pattern found at " << ( i - j ) << endl ;
        	j = patt[ j - 1 ];
		}

    }
    if (k == i) {
        printf("No Pattern Found\n");
    }
    else {
        printf("Found at %d\n", k);
    }

    return (0);
}
