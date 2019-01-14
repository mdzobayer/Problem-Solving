#include <iostream>

using namespace std;

class Date{
private:
    int month, day, year;

public:

//------Class constructor-------
    Date(int m, int d, int y){
        month = m;
        day = d;
        year = y;
    };
    Date(int m, int y){
        month = m;
        day = 0;
        year = y;
    };
//----------Default Constructor-----------
    Date(){
        month = 0;
        day = 0;
        year = 0;
    };
    int getMonth() const{
        return month;
    }
    int getDay() const{
        return day;
    }
    int getYear() const{
        return year;
    }

};
//--------------Operator Overloading-------------
bool operator > (const Date &d1, const Date &d2){
    if(d1.getYear() > d2.getYear())
        return true;
    else if((d1.getYear() == d2.getYear()) &&
            (d1.getMonth() > d2.getMonth()))
        return true;
    else if((d1.getYear() == d2.getYear()) &&
            (d1.getMonth() == d2.getMonth()) &&
            (d1.getDay() > d2.getDay()))
        return true;
    else
        return false;
}
bool operator >= (const Date &d1, const Date &d2){
    if(d1.getYear() > d2.getYear())
        return true;
    else if((d1.getYear() == d2.getYear()) &&
            (d1.getMonth() > d2.getMonth()))
        return true;
    else if((d1.getYear() == d2.getYear()) &&
            (d1.getMonth() == d2.getMonth()) &&
            (d1.getDay() > d2.getDay()))
        return true;
    else if((d1.getYear() == d2.getYear()) &&
            (d1.getMonth() == d2.getMonth()) &&
            (d1.getDay() == d2.getDay()))
        return true;
    else
        return false;
}
int main(){

    Date today(3,22,2011);
    Date tomorrow(3,23,2011);
    //Date tomorrow(3,22,2011);
    /*if (today > tomorrow)
        cout << "Today greater than tomorrow" << endl;
    else
        cout << "Tomorrow greater than today" << endl;
    */
    if (today >= tomorrow)
        cout << "Today is > or = to tomorrow" << endl;
    else
        cout << "Today is not > or = to tomorrow" << endl;

    return (0);
};


