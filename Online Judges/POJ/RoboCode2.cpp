#include <bits/stdc++.h>
#define SIZE 120+5

using namespace std;

struct point {
    int X, Y;

    void operator = (const point & p) {
        this->X = p.X;
        this->Y = p.Y;
    }
};

struct Tank {
    int X, Y, angle = 0;
    bool alive, moving;
};

struct Bullet {
    int X, Y, angle;
    bool isBack;

    void operator = (const Bullet &b) {
        this->X = b.X;
        this->Y = b.Y;
        this->angle = b.angle;
        this->isBack = b.isBack;
    }
};

struct Action {
    int time, tankID, actionType, angle = 0;

    // Action Types
    // 1 = Shoot
    // 2 = Move
    // 3 = Stop
    // 4 = Turn

    void operator = (const Action & a) {
        this->time = a.time;
        this->actionType = a.actionType;
        this->tankID = a.tankID;
        this->angle = a.angle;
    }
};

map < string , int > tankid;
vector < Action > actions[60];
Tank tanks[15];
int board[SIZE][SIZE];


bool isValid(int x, int y) {
    if (x < 0 || y < 0 || x > 120 || y > 120) return false;
    return true;
};
bool isValid(const point &p) {
    return isValid(p.X,p.Y);
};


int main() {

    freopen("in.txt", "r", stdin);

    int n, m, i, x, j, y, tn, turnAngle, currentTankID, currentTime;
    string name, order, singleCommand;

    Bullet aBullet, newBullet;
    Action anAction;

    while(cin >> n >> m) {

        if (n == 0 && m == 0) break;
        memset(board, 0, sizeof(board));

        cin.ignore(); // Ignore \n new line

        // Clear previous tank unique id
        tankid.clear();
        for (i = 0; i < 60; ++i) {
            actions[i].clear();
        }

        // Take tank information
        for (i = 1; i <= n; ++i) {
            cin >> name >> tanks[i].X >> tanks[i].Y >> tanks[i].angle;
            tankid[name] = i;
            tanks[i].alive = true;
            tanks[i].moving = false;
            board[tanks[i].X][tanks[i].Y] = i;
        }
        cin.ignore();

        // Take commands
        for (i = 1; i <= m; ++i) {
            getline(cin, order);

            // Remove all semicolones
            for (j = 0; j < order.size(); ++j) {
                if (order[j] == ';')
                    order[j] = ' ';
            }
            // Add order for pursing
            cout << order << endl;
            stringstream allCommands(order);

            // Extract all commands
            allCommands >> currentTime;
            allCommands >> name;
            currentTankID = tankid[name];   // Getting TankID

            anAction.time = currentTime;
            anAction.tankID = currentTankID;

    // Action Types
    // 1 = Shoot
    // 2 = Move
    // 3 = Stop
    // 4 = Turn

            while(allCommands >> singleCommand) {
                
                if(singleCommand == "TURN") {
                    allCommands >> turnAngle;
                    anAction.actionType = 4;
                    anAction.angle = turnAngle;
                    actions[currentTime].push_back(anAction);
                    
                }
                else if(singleCommand == "STOP") {
                    anAction.actionType = 3;
                    anAction.angle = 0;
                    actions[currentTime].push_back(anAction);
                }
                else if(singleCommand == "MOVE") {
                    anAction.actionType = 2;
                    anAction.angle = 0;
                    actions[currentTime].push_back(anAction);
                }
                else if (singleCommand == "SHOOT") {
                    anAction.actionType = 1;
                    anAction.angle = 0;
                    actions[currentTime].push_back(anAction);
                }
                anAction = actions[currentTime].back();
                cout << anAction.time << " " << anAction.tankID << " " <<  anAction.actionType << " " << anAction.angle << endl;
            }
        }

        // Simulation Part
        
        // Bullet Simulation Vector
        vector < Bullet > bullets1, bullets2;

        // 

        // Simulation Time Start
        for (currentTime = 0; currentTime <= 60; ++currentTime) {
            // Simulate Bullet
            bullets2.clear();
            for (int b1 = 0; b1 < bullets1.size(); ++b1) {
                if (bullets1[b1].isBack == true) {
                    // Previous Position Exist
                    if (bullets1[b1].angle == 0) {

                    }
                    else if (bullets1[b1].angle == 90) {

                    }
                    else if (bullets1[b1].angle == 180) {

                    }
                    else if (bullets1[b1].angle == 270) {

                    }
                }
                else {
                    // Previous position not exist
                    if (board[bullets1[b1].X][bullets1[b1].Y] != 0) {
                        // A Tank Found
                        currentTankID = board[bullets1[b1].X][bullets1[b1].Y];
                        tanks[currentTankID].alive = false;
                    }
                    else {
                        // An Empty cell
                        if (bullets1[b1].angle == 0) {
                            if (isValid(bullets1[b1].X + 20, bullets1[b1].Y)) {
                                bullets1[b1].X += 20;
                                bullets1[b1].isBack = true;
                                bullets2.push_back(bullets1[b1]);
                            }
                            else if (isValid(bullets1[b1].X + 10, bullets1[b1].Y)) {
                                bullets1[b1].X += 10;
                                bullets1[b1].isBack = false;
                                bullets2.push_back(bullets1[b1]);
                            }
                        }
                        else if (bullets1[b1].angle == 90) {
                            if (isValid(bullets1[b1].X, bullets1[b1].Y + 20)) {
                                bullets1[b1].Y += 20;
                                bullets1[b1].isBack = true;
                                bullets2.push_back(bullets1[b1]);
                            }
                            else if (isValid(bullets1[b1].X, bullets1[b1].Y + 10)) {
                                bullets1[b1].Y += 10;
                                bullets1[b1].isBack = false;
                                bullets2.push_back(bullets1[b1]);
                            }
                        }
                        else if (bullets1[b1].angle == 180) {
                            if (isValid(bullets1[b1].X - 20, bullets1[b1].Y)) {
                                bullets1[b1].X -= 20;
                                bullets1[b1].isBack = true;
                                bullets2.push_back(bullets1[b1]);
                            }
                            else if (isValid(bullets1[b1].X - 10, bullets1[b1].Y)) {
                                bullets1[b1].X -= 10;
                                bullets1[b1].isBack = false;
                                bullets2.push_back(bullets1[b1]);
                            }
                        }
                        else if (bullets1[b1].angle == 270) {
                            if (isValid(bullets1[b1].X, bullets1[b1].Y - 20)) {
                                bullets1[b1].Y -= 20;
                                bullets1[b1].isBack = true;
                                bullets2.push_back(bullets1[b1]);
                            }
                            else if (isValid(bullets1[b1].X, bullets1[b1].Y - 10)) {
                                bullets1[b1].Y -= 10;
                                bullets1[b1].isBack = false;
                                bullets2.push_back(bullets1[b1]);
                            }
                        }
                    }
                }
            }





        }
        // Simulation Time End

        // Now Search for Ans
        int aliveTanks = 0, ans;
        for (tn = 1; tn <= n; ++tn) {
            if (tanks[tn].alive == true) {
                ++aliveTanks;
                ans = tn;
            }
        }

        if (aliveTanks == 0 || aliveTanks > 1) {
            cout << "NO WINNER!" << endl;
        }
        else {
            map < string, int >::iterator it;
            for (it = tankid.begin(); it != tankid.end(); ++it) {
                if (it->second == ans) {
                    cout << it->first << endl;
                    break;
                }
            }
        }
    }

    return (0);
}
