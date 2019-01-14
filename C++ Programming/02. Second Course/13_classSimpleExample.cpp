#include <iostream>

using namespace std;

class Name{
private:
    string first, middle, last;

public:
    //-----------------Constructor-----------------
    Name(string fname, string mname, string lname){
    //void name(string fname, string mname, string lname){
        first = fname;
        middle = mname;
        last = lname;
    };

    string toString(){
        return first + " " + middle + " " + last;
    };
};

int main(){

    class Name myName("Zobayer", "Mahmud","Khan");
    //myName.name("Zobayer", "Mahmud","Khan");
    cout << myName.toString() << endl;
    return (0);
};
