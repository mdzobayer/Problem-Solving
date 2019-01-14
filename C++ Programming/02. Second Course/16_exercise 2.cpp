#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

string fileName = "c:\\data\\todo.txt";

int menu() {
    int choice;
    cout << "Main Menu" << endl << endl;
    cout << "0. Exit the program" << endl;
    cout << "1. Display the to-do list" << endl;
    cout << "2. Add item to to-do list" << endl;
    cout << "3. Remove item from to-do list"
        << endl;
    cout << endl;
    cout << "Enter a choice: ";
    cin >> choice;
    return choice;
}

void showList() {
    cout << "To-do List " << endl << endl;
    string line;
    int number = 1;
    ifstream inFile(fileName.c_str(), ios::in);
    if(!inFile) {
        cout << "File not found." << endl;
        exit(1);
    }
    getline(inFile, line);
    while (!inFile.eof()) {
        cout << number << ". " << line
             << endl;
        ++number;
        getline(inFile, line);
    };
    inFile.close();
    cout << endl << endl << endl;
}

void addItem() {
    cout << "Add Item " << endl << endl;
    cin.clear();
    cin.sync();
    ofstream outFile(fileName.c_str(), ios::app);
    string item;
    cout << "Enter an item: ";
    getline(cin, item);
    if (!outFile) {
        cout << "File not found." << endl;
        exit(1);
    }
    outFile << item << endl;
    outFile.close();
    cout << endl;
}

void removeItem() {
    int choice;
    showList();
    cin.clear();
    cin.sync();
    cout << "Which item do you want to remove? ";
    cin >> choice;
    vector<string> items;
    int number = 1;
    ifstream inFile(fileName.c_str(), ios::in);
    if(!inFile) {
        cout << "File not found. " << endl;
        exit(1);
    }
    string item;
    getline(inFile, item);
    while (!inFile.eof()) {
        if (number != choice)
            items.push_back(item);
        ++number;
        getline(inFile, item);
    }
    inFile.close();
    ofstream outFile(fileName.c_str(), ios::out);
    if(!outFile) {
        cout << "File not found. " << endl;
        exit(1);
    }
    for(int i = 0; i < items.size(); ++i)
        outFile << items[i] << endl;
    outFile.close();
}

int main()
{
    int choice;
    while(choice != 0) {
        choice = menu();
        switch(choice) {
            case 1:
                showList();
                break;
            case 2:
                addItem();
                break;
            case 3:
                removeItem();
                break;
            case 0:
                break;
            default:
                cout << "Don't recognize input."
                    << endl;
        }
    }
    return 0;
}
