#include <iostream>

using namespace std;

class Date{
private:
    int month, day, year;

public:

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
    int getMonth() {
        month = 56;
        return month;
    }
    int getDay(){
        return day;
    }
    int getYear(){
        return year;
    }
    void displayDate(){
        cout << month << "/" << day << "/" << year;
    };
    void addDay(int n){
        day += n;
    };
    void addMonth(int n){
        month += n;
    };
    bool equals(Date dt){
        if((month == dt.month) &&
           (day == dt.day) &&
           (year == dt.year))
            return true;
        else
            return false;
    };
};
int main(){
    cout << "Today Object" << endl;
    Date today(3,20,2011);
    today.displayDate();
    cout << endl;
    today.addDay(5);
    today.displayDate();
    cout << endl;
    today.addMonth(2);
    today.displayDate();
    cout << endl;
    cout << "Tomorrow object" << endl;
    Date tomorrow = today;
    tomorrow.addDay(1);
    if(tomorrow.equals(today))
        cout << "The same day" << endl;
    else
        cout << "A different day" << endl;

    return (0);
};
