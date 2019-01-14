#include <iostream>
#include <list>

using namespace std;

void display(list<string> lyst) {
    list<string>::iterator iter = lyst.begin();
    while(iter != lyst.end()){
        cout << *iter << endl;
        ++iter;
    }
}

int main()
{
    list<string> names;
    names.push_back("Mary");
    names.push_back("Zach");
    names.push_back("Elizabeth");
    names.push_front("Zobayer");
    display(names);
    //cout << line[1] << endl;
    //cout << names.back() << endl;

    cout << "First item: " << names.front() << endl;
    cout << "Last item: " << names.back() << endl;
    cout << endl << "After Reverse" << endl;
    names.reverse();
    display(names);
    cout << "First item: " << names.front() << endl;
    cout << "Last item: " << names.back() << endl;
    cout << endl << "After Sort" << endl;
    names.sort();
    display(names);
    cout << endl << "After push_front" << endl;
    names.push_front("Barry");
    display(names);
    cout << "Size of list: " << names.size() <<endl;
    cout << endl << "After Remove" << endl;
    names.remove("Elizabeth");
    display(names);
    cout << endl << "After pop_front & pop_back" << endl;
    names.pop_front();
    names.pop_back();
    display(names);
    cout << endl << "After Clear" << endl;
    names.clear();
    if (names.empty()) {
        cout << "List is empty." << endl;
    }
    else
        cout << "List is not empty." << endl;
    return 0;
}

