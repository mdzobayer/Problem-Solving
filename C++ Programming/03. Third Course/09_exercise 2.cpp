#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

class Queue {
private:
    string datastore[100];
    int back;
    const static int front = 0;
    /*
      For the front we are going to create constant static data
      member because the front will never change. The
      front of the queue is always the zero element of
      datastore. So we make that const because it run in a
      class we have to make it static. That way we can't
      ever change the front by accident worm perpuss
    */
    void shift() {
        for(int i = front; i <= back; ++i) {
            datastore[i] = datastore[i+1];
        }
        --back;
    }
public:
    Queue() {
        back = -1;
    }
    void in(string value) {
        ++back;
        datastore[back] = value;
    }
    string out() {
        string retVal = datastore[front];
        shift();
        return retVal;
    }
    void show() {
        for(int i = front; i <= back; ++i) {
            cout << datastore[i] << " ";
        }
        cout << endl;
    }
    int count() {
        int cnt = 0;
        for(int i = 0; i <= back; ++i) {
            ++cnt;
        }
        return cnt;
    }
    string qFront() {
        return datastore[front];
    }
    string qBack() {
        return datastore[back];
    }
    bool isEmpty() {
        if(back == -1) {
            return true;
        }
        else {
            return false;
        }
    }
    void clear() {
        for(int i = front; i <= back; ++i) {
            datastore[i] = "";
        }
    }
};

int main() {

    Queue men;
    Queue women;
    string name = "c:\\data\\dance.dat";
    string line, sex;
    ifstream inFile(name.c_str());
    while (!inFile.eof()) {
        getline(inFile, line);
        sex = line.substr(0,1);
        if (sex == "M") {
            string name2 = line.substr(2);
            men.in(name2);
        }
        else {
            string name2 = line.substr(2);
            women.in(name2);
        }
    }
    while(!men.isEmpty() && !women.isEmpty()) {
        cout << "The dancing partners will be: ";
        cout << men.qFront() << " and ";
        cout << women.qFront() << endl;
        men.out();
        women.out();
    }
    if (women.isEmpty()) {
        cout << "There are " << men.count()
             << " men waiting for the next round."
             << endl;
        cout << men.qFront()
             << "will be first to get a partner."
             << endl;
    }
    if (men.isEmpty()) {
        cout << "There are " << women.count()
             << " women waiting for the next round."
             << endl;
        cout << women.qFront()
             << "will be first to get a partner."
             << endl;
    }
    inFile.close();

    return (0);
};

