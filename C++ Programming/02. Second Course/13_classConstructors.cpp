#include <iostream>

using namespace std;

class Date{
private:
    int month, day, year;

public:
    //----------------Constructor------------------
    /* After you define the class for a class the next step
    is to build what a called class constructor.

    ** A constructor is a function that allows to initialize
    a class object with data. either all of the data that
    you need store on the class or just  part of it that
    depends on the needs and most cases you have constructor
    for possible

    ** A Constructor always starts with the name of the class

    */
    //Class constructor can be overloading
    Date(int m, int d, int y){
        month = m;
        day = d;
        year = y;
    }
    Date(int m, int y){
        month = m;
        day = 0;
        year = y;
    }
    //------------Default Constructor-------------
    Date(){
        month = 0;
        day = 0;
        year = 0;
    };

};
int main(){
    class Date today(3,20,2011);
    class Date yesterDay(3,2011);
    class Date tomorrow;


    return (0);
};
