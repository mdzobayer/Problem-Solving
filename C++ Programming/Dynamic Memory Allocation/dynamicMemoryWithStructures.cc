#include <iostream>
#include <cstdlib>
#include <cstdio>


using namespace std;

int main() {

    struct person {
        string name;
        int age;
    };
    int client, clientAge;
    cout << "Enter how many Client: ";
    cin >> client;
    getchar();
    struct person *clients;

    clients = new(nothrow) person[client];

    string clientName;
    for (int i = 0; i < client; ++i) {
        cout << "Client Name: ";
        getline(cin,clientName);
        clients[i].name = clientName;
        cout << "Enter Client Age: ";
        cin >> clientAge;
        getchar();
        clients[i].age = clientAge;
    }
    for (int i = 0; i < client; ++i) {
        cout << clients[i].name << endl;
        cout << clients[i].age << endl;
    }

    delete []clients;

    return (0);
}
