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

    void setDate(int m, int d, int y){
        month = m;
        day = d;
        year = y;
    };
    void setMonth(int m){
        if(m < 1 || m > 12){
            cout << "Bad month value";
        }
        else
            month = m;
    };
    void setDay(int d){
        day = d;
    }
    void setYear(int y){
        year = y;
    }

    int getMonth(){
        return month;
    }
    int getDay(){
        return day;
    }
    int getYear(){
        return year;
    }

    void displayDate(){
        cout << getMonth() << "/" << day << "/" << year;
    }
};
int main(){
    Date today;
    today.setDate(3,20,2011);
    cout << "Month: " << today.getMonth() << endl;
    cout << "Day: " << today.getDay() << endl;
    cout << "Year: " << today.getYear() << endl;
    //cout << today.getMonth() << "/" << today.getDay() << "/" << today.getYear();
    today.displayDate();
    today.setMonth(4);
    today.setDay(22);
    today.setYear(2011);
    cout << endl;
    today.displayDate();
    return (0);
}
