#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class List {
private:
    vector<T> datastore;
public:
    List() {};

    void add(T item) {
        datastore.push_back(item);
    };
    void display() {
        for(int i = 0; i < datastore.size(); ++i) {
            cout << datastore[i] << endl;
        }
    }
};
int main() {
    List<string> grocery;
    grocery.add("milk");
    grocery.add("eggs");
    grocery.add("bread");
    grocery.display();
    cout << endl;
    List<int> grades;
    grades.add(85);
    grades.add(87);
    grades.add(84);
    grades.display();
    cout << endl;
    List<char> ch;
    ch.add('Z');
    ch.add('u');
    ch.add('b');
    ch.add('o');
    ch.display();
    return (0);
};
