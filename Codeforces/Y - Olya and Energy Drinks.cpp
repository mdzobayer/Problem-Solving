#include <bits/stdc++.h>

using namespace std;
int n, m, k, x2, y2;
string str[1000+5];

struct point {
    int xx, yy, step;
    point operator = (point t) {
        this->xx = t.xx;
        this->yy = t.yy;
        this->step = t.step;
    }
};
bool isValid(const point &t,const point &c) {
    if (t.xx < 0 || t.yy < 0)
        return false;
    if (t.xx > (n - 1) || t.yy > (m - 1))
        return false;
    int i, s, e;
    //cout << "Checking " << t.xx << " " << t.yy << endl;
    if (c.xx == t.xx) {

        s = min(c.yy, t.yy);
        e = max(c.yy, t.yy);
        //cout << "s e " << s << " " << e << endl;
        if (s == c.yy) {
            ++s;
        }
        else {
            --e;
        }
        for (i = s; i <= e; ++i) {
            if (str[c.xx][i] == '#') {
                //cout << "Error " << c.xx << " " << i << endl;
                return false;
            }
        }
    }
    else {
        s = min(c.xx, t.xx);
        e = max(c.xx, t.xx);
        if (s == c.xx) {
            ++s;
        }
        else {
            --e;
        }
        for (i = s; i <= e; ++i) {
            if (str[i][c.yy] == '#') return false;
        }
    }

    return true;
}

int dir [2][8] = {{-1,0,0,1,-1,-1,1,1},
                  {0,-1,1,0,-1,1,1,-1}};

int main() {

    //freopen("in.txt", "r", stdin);

    int i, j, x1, y1, x2, y2, ava;

    cin >> n >> m >> k;
    ava = n * n;
    for (i = 0; i < n; ++i) {
        cin.ignore();
        cin >> str[i];
        //cout << str[i] << endl;
    }
    cin >> x1 >> y1 >> x2 >> y2;
    //cout << "==== " << x1 << endl;

    --x1;
    --x2;
    --y1;
    --y2;
    //cout << "Desti " << x2 << " " << y2 << endl;
    //cout << str[2][3] << endl;

    point currPoint, newPoint;

    currPoint.xx = x1;
    currPoint.yy = y1;
    currPoint.step = 0;
    --ava;
    queue < point > q;
    q.push(currPoint);

    while(!q.empty()) {
        currPoint = q.front();
        q.pop();
        str[currPoint.xx][currPoint.yy] = '#';
        //cout << "poped " << currPoint.xx << " " << currPoint.yy << endl;
        for (i = k; i > 0; --i) {
            for (j = 0; j < 4; ++j) {
                newPoint.xx = currPoint.xx + (dir[0][j] * i);
                newPoint.yy = currPoint.yy + (dir[1][j] * i);
                newPoint.step = currPoint.step + 1;

                //cout << "New Point " << newPoint.xx << " " << newPoint.yy << endl;
//                if ((newPoint.xx == 2) && (newPoint.yy == 3))
//                    cout << str[newPoint.xx][newPoint.yy] << endl;
//
                if (isValid(newPoint, currPoint)) {
                    if (newPoint.xx == x2 && newPoint.yy == y2) {
                        //cout << i << "  " << newPoint.step << endl;
                        cout << newPoint.step << endl;
                        return (0);
                    }
                    //cout << str[newPoint.xx][newPoint.yy] << endl;
                    //cout << "--- Pushed " << newPoint.xx << " " << newPoint.yy << endl;
                    //cout << str[newPoint.xx][newPoint.yy] << endl;
                    q.push(newPoint);
                    str[newPoint.xx][newPoint.yy] = '#';
                    --ava;
                    if (ava < 1) {
                        cout << "-1" << endl;
                        return (0);
                    }
                }
            }
        }
        //
    }

    cout << "-1" << endl;

    return (0);
}
