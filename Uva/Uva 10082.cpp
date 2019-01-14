
#include <cstdio>
#include <cstring>
#include <map>
#include <utility>
using namespace std;

int main() {

    map<char, char> press;
    press.insert(pair<char, char> ('A', 'A'));
    press.insert(pair<char, char> ('B', 'V'));
    press.insert(pair<char, char> ('C', 'X'));
    press.insert(pair<char, char> ('D', 'S'));
    press.insert(pair<char, char> ('E', 'W'));
    press.insert(pair<char, char> ('F', 'D'));
    press.insert(pair<char, char> ('G', 'F'));
    press.insert(pair<char, char> ('H', 'G'));
    press.insert(pair<char, char> ('I', 'U'));
    press.insert(pair<char, char> ('J', 'H'));
    press.insert(pair<char, char> ('K', 'J'));
    press.insert(pair<char, char> ('L', 'K'));
    press.insert(pair<char, char> ('M', 'N'));
    press.insert(pair<char, char> ('N', 'B'));
    press.insert(pair<char, char> ('O', 'I'));
    press.insert(pair<char, char> ('P', 'O'));
    press.insert(pair<char, char> ('Q', 'Q'));
    press.insert(pair<char, char> ('R', 'E'));
    press.insert(pair<char, char> ('S', 'A'));
    press.insert(pair<char, char> ('T', 'R'));
    press.insert(pair<char, char> ('U', 'Y'));
    press.insert(pair<char, char> ('V', 'C'));
    press.insert(pair<char, char> ('W', 'Q'));
    press.insert(pair<char, char> ('X', 'Z'));
    press.insert(pair<char, char> ('Y', 'T'));
    press.insert(pair<char, char> ('Z', 'Z'));
    press.insert(pair<char, char> (' ', ' '));
    press.insert(pair<char, char> ('[', 'P'));
    press.insert(pair<char, char> (']', '['));
    press.insert(pair<char, char> (';', 'L'));
    press.insert(pair<char, char> (',', 'M'));
    press.insert(pair<char, char> ('.', ','));
    press.insert(pair<char, char> ('/', '.'));
    press.insert(pair<char, char> ('\'', ';'));
    press.insert(pair<char, char> ('\n', '\n'));
    press.insert(pair<char, char> ('\\', ']'));

    press.insert(pair<char, char> ('`', '`'));
    press.insert(pair<char, char> ('1', '`'));
    press.insert(pair<char, char> ('2', '1'));
    press.insert(pair<char, char> ('3', '2'));
    press.insert(pair<char, char> ('4', '3'));
    press.insert(pair<char, char> ('5', '4'));
    press.insert(pair<char, char> ('6', '5'));
    press.insert(pair<char, char> ('7', '6'));
    press.insert(pair<char, char> ('8', '7'));
    press.insert(pair<char, char> ('9', '8'));
    press.insert(pair<char, char> ('0', '9'));
    press.insert(pair<char, char> ('-', '0'));
    press.insert(pair<char, char> ('=', '-'));

    char str;
    while( scanf("%c", &str) == 1) {
        printf("%c", press[str]);
    }

    return (0);
}
