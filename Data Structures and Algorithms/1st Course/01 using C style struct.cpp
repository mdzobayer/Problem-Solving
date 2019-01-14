#include <iostream>

using namespace std;
// define the structure
struct Book{
    string title;
    double price;
    bool isPublished;
    bool isHardback;
};

int main(){

    // create a variable with that struct type
    Book first;

    // set member variables
    first.title = "Dark and Stormy Night";
    first.price = 12.95;
    first.isPublished = true;
    first.isHardback = false;
    /*
    Difference Between structs and classes
        A nice slide duration 01:43
        */
    return (0);
}
