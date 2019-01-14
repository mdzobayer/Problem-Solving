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
    };
    Date(int m, int y){
        month = m;
        day = 0;
        year = y;
    };
    //------------Default Constructor-------------
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
//Non-member functions
istream &operator >> (istream &input, Date &d){
    int month, day, year;
    char slash1, slash2;
    input >> month >> slash1 >> day
        >> slash2 >> year;
    d = Date(month, day, year);
    return input;
};
ostream &operator << (ostream &output, const Date &d){
    return output << d.getMonth() << "/"
                << d.getDay() << "/"
                << d.getYear();
};
int main(){

    Date today;
    cout << "Enter a date (mm/dd/yyyy): ";
    cin >> today;
    cout << "Today is: ";
    cout << today << endl;
    return (0);
};

