#include <bits/stdc++.h>

using namespace std;

int main() {

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int hh, mm, se, previousTime, currentTime;
    double speed, previousSpeed = 0.0, distance = 0.0, tempDis = 0.0;
    string s;

    while(getline(cin, s)) {
        //printf("I am here\n");
        speed = -1;
        stringstream ss(s);
        ss >> hh;
        ss.ignore();
        ss >> mm;
        ss.ignore();
        ss >> se;
        ss.ignore();
        ss >> speed;
        //cout << hh << " " << mm << " " << se << " " << speed << endl;
        if(speed != -1) {
            currentTime = hh * 60;
            currentTime += mm;
            currentTime *= 60;
            currentTime += se;

            distance += ((currentTime - previousTime) * previousSpeed) / 3600.0;
            previousTime = currentTime;
            previousSpeed = speed;
        }
        else {
            /// Show formated output
            if (hh < 10) printf("0%d:", hh);
            else printf("%d:", hh);

            if (mm < 10) printf("0%d:", mm);
            else printf("%d:", mm);

            if (se < 10) printf("0%d ", se);
            else printf("%d ", se);

            currentTime = hh * 60;
            currentTime += mm;
            currentTime *= 60;
            currentTime += se;

            tempDis = ((currentTime - previousTime) * previousSpeed) / 3600.0;
            tempDis += distance;
            printf("%0.2lf km\n", tempDis);
        }
    }

    return (0);
}
