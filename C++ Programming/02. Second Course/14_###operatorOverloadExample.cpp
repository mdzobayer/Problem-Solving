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
    int getMonth() const{
        return month;
    };
    int getDay() const{
        return day;
    };
    int getYear() const{
        return year;
    };
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

bool operator == (const Date &d1, const Date &d2){
    return ((d1.getMonth() == d2.getMonth()) &&
            (d1.getDay() == d2.getDay()) &&
            (d1.getYear() == d2.getYear()));
}
int main(){

    Date today(3,22,2011);
    Date tomorrow = today;
    //tomorrow.addDay(1);
    if(tomorrow == today)
        cout << "The same day" << endl;
    else
        cout << "Different day" << endl;

    return (0);
};
