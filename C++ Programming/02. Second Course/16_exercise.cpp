#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
string fileName = "c:\\data\\todo.txt";
int menu(){
    int choice;
    cout << "0. Exit the person" << endl;
    cout << "1. Display the to-do list" << endl;
    cout << "2. Add item to to-do list";
    cout << endl;
    cout << "Enter a choice: ";
    cin >> choice;

    return choice;
};
void showList() {
    string line;
    ifstream inFile(fileName.c_str(), ios::in);
    if(!inFile){
        cout << "File not found." << endl;
        exit(1);
    };
    getline(inFile, line);
    while (!inFile.eof()){
        cout << line << endl;
        getline(inFile, line);
    };
    inFile.close();
    cout << endl << endl << endl;
};
void addItem() {
    /*When you getting input from the consol. It has posibilitys that the old object still here. I is called the buffer.*/
    cin.clear();    //Clear Buffer
    cin.sync();     //(Sincet)Make sure ready to get new input from the consol
    ofstream outFile(fileName.c_str(), ios::app);
    if(!outFile){
        cout << "File not found." << endl;
        exit(1);
    };
    string item;
    cout << "Enter an item: ";
    getline(cin,item);

    outFile << item << endl;
    outFile.close();
    cout << endl;
};

int main(){
    int choice;
    while(choice != 0){
        choice = menu();
        switch(choice){
        case 1:
            showList();
            break;
        case 2:
            addItem();
            break;
        case 0:
            break;
        default:
            cout << "Don't recognize input." << endl;
        };
    };
    return (0);
};
