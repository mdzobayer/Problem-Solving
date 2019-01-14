#include <cstdio>
#include <cstring>
#include <map>
#include <utility>
using namespace std;

int main() {

    map<char, int> press;
    press.insert(pair<char, int> ('a', 1));
    press.insert(pair<char, int> ('b', 2));
    press.insert(pair<char, int> ('c', 3));
    press.insert(pair<char, int> ('d', 1));
    press.insert(pair<char, int> ('e', 2));
    press.insert(pair<char, int> ('f', 3));
    press.insert(pair<char, int> ('g', 1));
    press.insert(pair<char, int> ('h', 2));
    press.insert(pair<char, int> ('i', 3));
    press.insert(pair<char, int> ('j', 1));
    press.insert(pair<char, int> ('k', 2));
    press.insert(pair<char, int> ('l', 3));
    press.insert(pair<char, int> ('m', 1));
    press.insert(pair<char, int> ('n', 2));
    press.insert(pair<char, int> ('o', 3));
    press.insert(pair<char, int> ('p', 1));
    press.insert(pair<char, int> ('q', 2));
    press.insert(pair<char, int> ('r', 3));
    press.insert(pair<char, int> ('s', 4));
    press.insert(pair<char, int> ('t', 1));
    press.insert(pair<char, int> ('u', 2));
    press.insert(pair<char, int> ('v', 3));
    press.insert(pair<char, int> ('w', 1));
    press.insert(pair<char, int> ('x', 2));
    press.insert(pair<char, int> ('y', 3));
    press.insert(pair<char, int> ('z', 4));
    press.insert(pair<char, int> (' ', 1));

    int test, j, keypadPress;
    char str[110];
    scanf("%d", &test);
    getchar();
    for (int i = 1; i <= test; ++i) {
        scanf(" %[^\n]", &str);
        //gets(str);
        keypadPress = 0;
        int n = strlen(str);
        for(j = 0; j < n; ++j) {
            keypadPress += press[str[j]];
        }
        printf("Case #%d: %d\n",i, keypadPress);
    }

    return (0);
}
