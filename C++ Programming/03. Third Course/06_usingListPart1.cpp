#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<string> names;
    names.push_back("Zobayer");
    names.push_back("Mary");
    names.push_front("Zach");
    names.push_back("Elizabeth");
    names.push_front("Apple");
    names.emplace_back("Anon");

    list<string>::iterator iter = names.begin();
    while (iter != names.end()) {
        cout << *iter << endl;
        ++iter;
    }
    cout << endl << endl;
    cout << "First item: " << names.front() << endl;
    cout << "Last item: " << names.back() << endl;
    cout << endl << endl;
    names.reverse();
    list<string>::iterator riter = names.begin();
    while (riter != names.end()) {
        cout << *riter << endl;
        ++riter;
    }
    cout << "First item: " << names.front() << endl;
    cout << "Last item: " << names.back() << endl;

    names.sort();
    list<string>::iterator siter = names.begin();
    while (siter != names.end()) {
        cout << *siter << endl;
        ++siter;
    }
    cout << "First item: " << names.front() << endl;
    cout << "Last item: " << names.back() << endl;

    return 0;
}





