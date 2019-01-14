#include <iostream>
#include <vector>
using namespace std;

int main(){
    /*
    Three ways to adding data into a vector
    01. push_back,
    02. direct assignment via a subscript,
    03. By using default data in the
        initialization statement
    */
    vector<string> names;
    names.push_back("David");
    names.push_back("Raymond");
    names.push_back("Cynthia");

    names[0] = "David";
    names[1] = "Raymond";
    names[2] = "Cynthia";

    vector<int> numbers(1000,0);

    return (0);
}
