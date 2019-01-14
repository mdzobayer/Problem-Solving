#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<string> line;
    line.push_back("Customer 1");
    line.push_front("Customer 2");
    line.push_back("Customer 3");
    for (int i = 0; i < line.size(); ++i) {
        cout << line[i] << endl;
    }
    line.pop_front();
    line.pop_back();
    for (int i = 0; i < line.size(); ++i) {
        cout << line[i] << endl;
    }
    cout << "Size of line: " << line.size() << endl;

    return (0);
}
