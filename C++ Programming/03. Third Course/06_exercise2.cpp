#include <iostream>
#include <deque>
#include <fstream>
#include <string>

using namespace std;

int main(){
    deque<string> names;
    ifstream nameList;
    nameList.open("C:\\Users\\Zobayer\\names.txt");
    string line;
    while(!nameList.eof()) {
        getline(nameList, line);
        string::iterator it = line.end();
        --it;
        size_t pos = line.find(" ");
        string name = line.substr(0,pos);
        if (*it == 'p')
            names.push_front(name);
        else
            names.push_back(name);
    }
    deque<string>::iterator it = names.begin();
    while(it != names.end()) {
        cout << *it << endl;
        ++it;
    }
    for(it = names.begin(); it < names.end(); ++it){
        cout << *it << endl;
    }
    nameList.close();

    return (0);
};
