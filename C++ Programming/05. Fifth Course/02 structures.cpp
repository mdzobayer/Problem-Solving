#include <iostream>

using namespace std;
typedef struct{
    int dd;
    int mm;
    int ccyy;
}date;
struct employee{
    int employee_number;
    date dob;
    date start_date;
};
struct worker {
    int startday;
    int startmonth;
    int startyear;
    int numberOfDependants;
    int numberOfYearsDriving;
    bool married;
    bool driver;
    bool ownscar;
    bool wearsGlasses;
};
struct smallworker {
    char startday;
    char startmonth;
    short startyear;
    char numberOfDependants;
    char numberOfYearsDriving;
    bool married;
    bool driver;
    bool ownscar;
    bool wearsGlass;
};
struct tinyworker {
    // bitwise variable declaration
    unsigned startday :5;
    unsigned startmonth :3;
    unsigned startyear :11;
    unsigned numberOfDependants :5;
    unsigned numberOfYearsDrivig :7;
    unsigned married :1;
    unsigned driver :1;
    unsigned ownscar :1;
    unsigned wearsGlass :1;
};
int main() {

    date VEDay{16,12,1971 };
    cout << "VEDay is " << VEDay.dd << "\\" << VEDay.mm << "\\" << VEDay.ccyy << endl;

    employee me;
    me.employee_number = 12345;
    me.dob.dd = 21;
    me.dob.mm = 5;
    me.dob.ccyy = 1998;
    me.start_date.dd = 15;
    me.start_date.mm = 11;
    me.start_date.ccyy = 2001;
    cout << "Your Id is " << me.employee_number << endl;
    cout << "Your Date of Birth is "
         << me.dob.dd << "\\" << me.dob.mm << "\\" << me.dob.ccyy << endl;
    cout << "Your Date of Start is "
         << me.start_date.dd << "\\" << me.start_date.mm << "\\" << me.start_date.ccyy << endl;

    employee *pyou;
    pyou = new(nothrow) employee;
    pyou->employee_number = 15;
    pyou->dob.dd = 12;
    pyou->dob.mm = 6;
    pyou->dob.ccyy = 1997;
    pyou->start_date.dd = 25;
    pyou->start_date.mm = 8;
    pyou->start_date.ccyy = 2002;
    cout << "Your Id is " << pyou->employee_number << endl;
    cout << "Your Date of Birth is "
         << pyou->dob.dd << "\\" << pyou->dob.mm << "\\" << pyou->dob.ccyy << endl;
    cout << "Your Date of Start is "
         << pyou->start_date.dd << "\\" << pyou->start_date.mm << "\\" << pyou->start_date.ccyy << endl;

    delete pyou;

    worker Me;
    Me.driver = true;

    smallworker you;
    you.ownscar = true;

    tinyworker him;
    him.startmonth = 7;

    return (0);
}
