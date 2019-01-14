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
    void operator + (int n){
        day += n;
    }
    void operator - (int n){
        day -= n;
    }
    Date &operator += (int n){
        day += n;
        return *this;
    }
    Date &operator = (const Date &d){
        month = d.month;
        day = d.day;
        year = d.year;
        return *this;
    }
};
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

    Date today(3,22,2011);
    cout << today << endl;
    today + 3;
    cout << today << endl;
    //today - 1;
    //cout << today << endl;
    Date tomorrow;
    tomorrow = today;
    cout << tomorrow << endl;

    return (0);
};


