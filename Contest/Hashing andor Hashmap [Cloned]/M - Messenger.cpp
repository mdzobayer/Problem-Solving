#include <iostream>
#include <sstream>
#include <map>
#include <cstdio>

using namespace std;

map<long long int, long long int> patt;
string inputText, inputPattern, text, pattern;

int main() {

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    long long int n, m, i, j, k, count;
    char ch;
    scanf("%lld %lld", &n, &m);
    getchar();

    text = "";
    pattern = "";

    /// Process with given text
    getline(cin, inputText);
    for ( i = 0; i < inputText.size(); ++i) {
        if (inputText[i] == '-')
            inputText[i] = ' ';
    }
    stringstream ss(inputText);
    while ( ss >> n >> ch) {
        for (i = 0; i < n; ++i) {
            text += ch;
        }
    }
    inputText.clear();
    //cout << text << endl;

    /// Process with given pattern
    getline(cin, inputPattern);
    for ( i = 0; i < inputPattern.size(); ++i) {
        if (inputPattern[i] == '-')
            inputPattern[i] = ' ';
    }

    stringstream sss(inputPattern);
    while (sss >> n >> ch) {
        for (i = 0; i < n; ++i) {
            pattern += ch;

        }
    }
    inputPattern.clear();
    //cout << "Input Pattern : " << pattern << endl;

    /// Now processing with KMP Algorithm
    //m = text.size();
    //long long int patt[m + 5];

    /// Preprocessing KMP array
    patt[0] = 0;
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

    count = 0;
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
            ++count;
        	//cout << "pattern found at " << ( i - j ) << endl ;
        	j = patt[ j - 1 ];
		}

    }
    printf("%lld\n", count);


    return (0);
}
