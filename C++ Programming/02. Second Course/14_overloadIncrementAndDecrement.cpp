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
    int getMonth() const{
        return month;
    }
    int getDay() const{
        return day;
    }
    int getYear() const{
        return year;
    }
    Date &operator ++ () {
        ++day;
        return *this;
    }
    Date &operator -- () {
        --day;
        return *this;
    }
    Date &operator ++ (int){
        Date d = *this;
        ++*this;
        return d;
    }
    Date &operator -- (int){
        Date d = *this;
        --*this;
        return d;
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
    /*cout << today << endl;
    ++today;
    cout << today << endl;
    ++today;
    cout << today << endl;
    --today;
    cout << today << endl;*/
    cout << today << endl;
    today++;
    cout << today << endl;
    today++;
    cout << today << endl;
    today--;
    cout << today << endl;
    int i = 1;
    i++;
    cout << i << endl;
    int j = i++;
    cout << j << endl;

    return (0);
};



