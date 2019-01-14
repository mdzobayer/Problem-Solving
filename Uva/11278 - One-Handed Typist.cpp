#include <bits/stdc++.h>


using namespace std;


int main() {

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    char lib[255];
    int i;
    for (i = 0; i < 255; ++i) {
        lib[i] = (char) i;
    }

    lib['`'] = '`';
    lib['1'] = '1';
    lib['2'] = '2';
    lib['3'] = '3';
    lib['4'] = 'q';
    lib['5'] = 'j';
    lib['6'] = 'l';
    lib['7'] = 'm';
    lib['8'] = 'f';
    lib['9'] = 'p';
    lib['0'] = '/'; ///
    lib['-'] = '[';
    lib['='] = ']';
    lib['q'] = '4';
    lib['w'] = '5';
    lib['e'] = '6';
    lib['r'] = '.';
    lib['t'] = 'o';
    lib['y'] = 'r';
    lib['u'] = 's';
    lib['i'] = 'u';
    lib['o'] = 'y';
    lib['p'] = 'b';
    lib['['] = ';';
    lib[']'] = '=';
    lib['\\'] = '\\';
    lib['a'] = '7';
    lib['s'] = '8';
    lib['d'] = '9';
    lib['f'] = 'a';
    lib['g'] = 'e';
    lib['h'] = 'h';
    lib['j'] = 't';
    lib['k'] = 'd';
    lib['l'] = 'c';
    lib[';'] = 'k';
    lib['\''] = '-'; ///
    lib['z'] = '0';
    lib['x'] = 'z';
    lib['c'] = 'x';
    lib['v'] = ',';
    lib['b'] = 'i';
    lib['n'] = 'n';
    lib['m'] = 'w';
    lib[','] = 'v';
    lib['.'] = 'g';
    lib['/'] = '\''; ///

    lib['~'] = '~';
    lib['!'] = '!';
    lib['@'] = '@';
    lib['#'] = '#';
    lib['$'] = 'Q';
    lib['%'] = 'J';
    lib['^'] = 'L';
    lib['&'] = 'M';
    lib['*'] = 'F';
    lib['('] = 'P';
    lib[')'] = '?';
    lib['_'] = '{';
    lib['+'] = '}';  ///
    lib['Q'] = '$';
    lib['W'] = '%';
    lib['E'] = '^';
    lib['R'] = '>';
    lib['T'] = 'O';
    lib['Y'] = 'R';
    lib['U'] = 'S';
    lib['I'] = 'U';
    lib['O'] = 'Y';
    lib['P'] = 'B';
    lib['{'] = ':';
    lib['}'] = '+';
    lib['|'] = '|';  ///
    lib['A'] = '&';
    lib['S'] = '*';
    lib['D'] = '(';
    lib['F'] = 'A';
    lib['G'] = 'E';
    lib['H'] = 'H';
    lib['J'] = 'T';
    lib['K'] = 'D';
    lib['L'] = 'C';
    lib[':'] = 'K';
    lib['"'] = '_';  ///
    lib['Z'] = ')';
    lib['X'] = 'Z';
    lib['C'] = 'X';
    lib['V'] = '<';
    lib['B'] = 'I';
    lib['N'] = 'N';
    lib['M'] = 'W';
    lib['<'] = 'V';
    lib['>'] = 'G';
    lib['?'] = '"';
    lib[' '] = ' ';


    string s;

    while(getline(cin, s)) {
        for (i = 0; i < s.size(); ++i) {
            putchar(lib[s[i]]);
        }
        putchar('\n');
    }


    return (0);
}
