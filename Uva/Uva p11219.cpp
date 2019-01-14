#include <cstdio>
#include <iostream>

using namespace std;

int generateAge(int d1, int m1, int y1, int d2, int m2, int y2)
{
    int y, d, m, age;
    y = y2 - y1;
    m = m2 - m1;
    d = d2 - d1;
    if((m2 < m1)||((m1 == m2) && (d2 < d1))) {
        y = y - 1;
    }
    m = (12 - m1) + m2;
    if (d2 < d1) {
        d = d - 1;
    }
    //printf(" %d years,%d months and %d days", y, m, d);
    return y;
}

int main()
{
    int t, bDay, bMonth, bYear, cDay, cMonth, cYear, age;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        scanf("%d/%d/%d", &cDay, &cMonth, &cYear);
        scanf("%d/%d/%d", &bDay, &bMonth, &bYear);

        cout << "Case #" << i << ": ";
        if (bYear > cYear) {
            cout << "Invalid birth date" << endl;
            continue;
        }
        else if ((bYear == cYear) && (bMonth > cMonth)) {
            cout << "Invalid birth date" << endl;
            continue;
        }
        else if ((bYear == cYear) && (bMonth == cMonth) && (bDay > cDay)) {
            cout << "Invalid birth date" << endl;
            continue;
        }
        if (bYear == cYear && bMonth == cMonth && bDay == cDay) {
            cout << "0" << endl;
            continue;
        }

        age = generateAge(bDay, bMonth, bYear, cDay, cMonth, cYear);

        if (age > 130) {
            cout << "Check birth date" << endl;
        }
        else {
            cout << age << endl;
        }
    }

    return (0);
}
