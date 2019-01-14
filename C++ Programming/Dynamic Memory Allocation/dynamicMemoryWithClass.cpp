#include <iostream>
#include <cstdio>

using namespace std;
class person {
    private:
        string userName;
        int age;
    public:
        person() {
            userName = "";
            age = 0;
        }
        person(string uName, int a) {
            userName = uName;
            age = a;
        }
        int getAge() {
            return age;
        }
        string getName() {
            return userName;
        }
        void setName(string uName) {
            userName = uName;
        }
        void setAge(int a) {
            age = a;
        }
};
int main() {
    int stdCount;
    class person student;
    class person *students;
    cout << "Enter how many students: ";
    cin >> stdCount;
    getchar();

    students = new(nothrow) person[stdCount];
    if (students == NULL) {
        cerr << "Memory Allocation Error!" << endl;
    }
    string stdName;
    int stdAge;
    for (int i = 0; i < stdCount; ++i) {
        cout << "Enter Name: ";
        getline(cin, stdName);
        students[i].setName(stdName);
        cout << "Enter Age: ";
        cin >> stdAge;
        getchar();
        students[i].setAge(stdAge);
    }
    for (int i = 0; i < stdCount; ++i) {
        cout << students[i].getName() << endl;
        cout << students[i].getAge() << endl;
    }
    students[0].setName("Zobayer");
    students[0].setAge(19);
    students[1].setName("Abeer");
    students[1].setAge(25);

    delete [] students;

    return (0);
};
