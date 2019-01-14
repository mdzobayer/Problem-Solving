/* Display a software timer. */
#include <iostream>
#define DELAY 128000
using namespace std;

struct myTime
{
    int hours;
    int minutes;
    int seconds;
};
void delay() {
    long int t;
    for (t = 1; t < DELAY; ++t);
}
void update(struct myTime *t)
{
    t->seconds++;
    if (t->seconds == 60) {
        t->seconds = 0;
        t->seconds++;
    }
    if (t->minutes == 60) {
        t->minutes = 0;
        t->minutes++;
    }
    if (t->hours == 24) {
        t->hours = 0;
    }
    delay();
}
void display(struct myTime *t)
{
    printf("%02d: ", t->hours);
    printf("%02d: ", t->minutes);
    printf("%02d: ", t->seconds);
}
int main() {
    struct myTime systime;
    systime.hours = 0;
    systime.minutes = 0;
    systime.seconds = 0;

    for(int i = 0; i < 10; ++i) {
        update(&systime);
        display(&systime);
        cout << endl;
    }

    return (0);

}
