/*
2 2
A 0 0 90
B 0 120 180
1 A MOVE
2 A SHOOT
2 2
A 0 0 90
B 0 120 270
1 A SHOOT
2 B SHOOT
2 6
A 0 0 90
B 0 120 0
1 A MOVE
2 A SHOOT
6 B MOVE
30 B STOP
30 B TURN 180
30 B SHOOT
0 0

2 2
A 10 0 90
B 0 10 0
0 A SHOOT
0 B MOVE
2 2
A 10 0 90
B 0 20 0
0 A SHOOT
0 B MOVE
2 2
A 10 0 90
B 10 20 0
0 A SHOOT
0 B MOVE
2 2
A 10 0 90
B 0 0 0
0 B SHOOT
1 A MOVE
2 2
A 10 0 90
B 10 10 0
0 A SHOOT
0 B MOVE
2 2
A 10 0 90
B 10 20 0
0 A SHOOT
0 B MOVE
2 2
A 10 0 90
B 10 20 270
0 B MOVE
0 A SHOOT
2 2
A 0 0 90
B 0 120 180
1 A MOVE
2 A SHOOT
2 2
A 0 0 90
B 0 120 270
1 A SHOOT
2 B SHOOT
2 6
A 0 0 90
B 0 120 0
1 A MOVE
2 A SHOOT
6 B MOVE
30 B STOP
30 B TURN 180
30 B SHOOT
0 0

Answer:
NO WINNER!
A
NO WINNER!
B
NO WINNER!
NO WINNER!
A
A
NO WINNER!
B
*/

#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <sstream>
#define SIZE 720+5
#define MAXTIME 180+5

using namespace std;

class point {
public:
    int X, Y;

    void operator = (const point & p) {
        this->X = p.X;
        this->Y = p.Y;
    }
};

class Tank {
public:
    int X, Y, angle;
    bool alive, moving;
    string tankName;
};

class Bullet {
public:
    int angle, tankID;
    point attack;

    void operator = (const Bullet &b) {
        this->attack = b.attack;
        this->angle = b.angle;
        this->tankID = b.tankID;
    }
};

class Action {
public:
    int tankID, actionType, angle;

    // Action Types
    // 1 = Shoot
    // 2 = Move
    // 3 = Stop
    // 4 = Turn

    void operator = (const Action & a) {
        this->actionType = a.actionType;
        this->tankID = a.tankID;
        this->angle = a.angle;
    }
};

map < string , int > tankid;
vector < Action > actions[MAXTIME];
Tank tanks[15];
int board[SIZE][SIZE];


bool isValid(int x, int y) {
    if (x < 0 || y < 0 || x > 720 || y > 720) return false;
    return true;
};
bool isValid( point p) {
    return isValid(p.X,p.Y);
};

bool isTankThere( point p) {
    if (board[p.X][p.Y] == 0) return false;
    return true;
};

bool isShootedTank( Bullet b) {
    if (board[b.attack.X][b.attack.Y] == b.tankID) return true;
    return false;
}

int boardTankID( point p) {
    return board[p.X][p.Y];
};

bool isMoveable( int  X,  int  Y) {
    if (isValid(X, Y) == false) return false;

    if (board[X][Y] == 0) return true;
    return false;
}


int main() {

    freopen("in.txt", "r", stdin);

    int n, m, i, x, j, y, attackedTankID, turnAngle, currentTankID, currentTime;
    string name, order, singleCommand;

    Bullet aBullet, newBullet;
    Action anAction;

    while(cin >> n >> m) {

        if (n == 0 && m == 0) break;
        memset(board, 0, sizeof(board));

        cin.ignore(); // Ignore \n new line

        // Clear previous tank unique id
        tankid.clear();
        for (i = 0; i < MAXTIME; ++i) {
            actions[i].clear();
        }

        // Take tank information
        for (i = 1; i <= n; ++i) {
            cin >> name >> tanks[i].X >> tanks[i].Y >> tanks[i].angle;
            tankid[name] = i;

            tanks[i].X *= 6;
            tanks[i].Y *= 6;
            tanks[i].tankName = name;
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
            //cout << order << endl;
            stringstream allCommands(order);

            // Extract all commands
            allCommands >> currentTime;
            allCommands >> name;
            currentTankID = tankid[name];   // Getting TankID

            anAction.tankID = currentTankID;
            currentTime *= 6;

    // Action Types
    // 1 = Shoot
    // 2 = Move
    // 3 = Stop
    // 4 = Turn
            //cout << "Before Extract: " << order << endl;

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
                    //cout << "Before Push: " << currentTime << endl;
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
                //cout << "Commands: " << currentTime << " " << anAction.tankID << " " <<  anAction.actionType << " " << anAction.angle << endl;
            }

        }

        // Simulation Part

        // Bullet Simulation Vector
        vector < Bullet > bullets1, bullets2;
        bullets1.clear();
        bullets2.clear();
        //
        //cout << "CurrentTime: " << currentTime << endl;
        // Simulation Time Start
        for (currentTime = 0; currentTime < MAXTIME; ++currentTime) {

            
            // Now Simulate moving Tanks (Checked)
            if (currentTime % 2 == 0)
            for (int tn = 1; tn <= n; ++tn) {
                if (tanks[tn].moving == true && tanks[tn].alive == true) {

                    //cout << "TankID : " << tn << " Angle : " << tanks[tn].angle << endl;
                    if (tanks[tn].angle == 0) {
                        //cout << "CurrentTime: " << currentTime << " TankID: " << tn << endl;
                        if (isMoveable(tanks[tn].X + 10, tanks[tn].Y)) {
                            board[tanks[tn].X][tanks[tn].Y] = 0;

                            tanks[tn].X += 10;
                            board[tanks[tn].X][tanks[tn].Y] = tn;
                        }
                    }
                    else if (tanks[tn].angle == 90) {
                        //cout << "MovementTime: " << currentTime << " TankID: " << tn << endl;
                        if (isMoveable(tanks[tn].X, tanks[tn].Y + 10)) {
                            board[tanks[tn].X][tanks[tn].Y] = 0;

                            tanks[tn].Y += 10;
                            board[tanks[tn].X][tanks[tn].Y] = tn;
                        }
                    }
                    else if (tanks[tn].angle == 180) {
                        if (isMoveable(tanks[tn].X - 10, tanks[tn].Y)) {
                            board[tanks[tn].X][tanks[tn].Y] = 0;

                            tanks[tn].X -= 10;
                            board[tanks[tn].X][tanks[tn].Y] = tn;
                        }
                    }
                    else if (tanks[tn].angle == 270) {
                        if (isMoveable(tanks[tn].X, tanks[tn].Y - 10)) {
                            board[tanks[tn].X][tanks[tn].Y] = 0;

                            tanks[tn].Y -= 10;
                            board[tanks[tn].X][tanks[tn].Y] = tn;
                        }
                    }
                    //cout << "Time : " << currentTime<< " TankID : " << tn << " " << tanks[tn].X << " " << tanks[tn].Y << endl;
                }
            }

            // Simulate Bullet
            bullets2.clear();
            for (int b1 = 0; b1 < bullets1.size(); ++b1) {
                //cout << "BTime: " << currentTime << " " << bullets1[b1].attack[0].X << " " << bullets1[b1].attack[0].Y << " Angle : " <<  bullets1[b1].angle << endl;
                //cout << "BTime: " << currentTime << " " << bullets1[b1].attack[1].X << " " << bullets1[b1].attack[1].Y << " Angle : " <<  bullets1[b1].angle << endl;
                if (isValid(bullets1[b1].attack)) {
                    if (isTankThere(bullets1[b1].attack) == true && isShootedTank(bullets1[b1]) == false) {
                        // Found a tank
                        //cout << "First attack Position" << endl;
                        //cout << bullets1[b1].attack[0].X << " " << bullets1[b1].attack[0].Y << endl;
                        attackedTankID = boardTankID(bullets1[b1].attack);
                        //cout << "Time : " << currentTime << " Attacked Tank : " << attackedTankID << endl;
                        tanks[attackedTankID].alive = false;
                    }
                    else {
                            // No tank on position
                        aBullet = bullets1[b1];
                        if (bullets1[b1].angle == 0) {
                            aBullet.attack.X += 10;
                        }
                        else if (bullets1[b1].angle == 90) {
                                aBullet.attack.Y += 10;
                        }
                        else if (bullets1[b1].angle == 180) {
                                aBullet.attack.X -= 10;
                        }
                        else if (bullets1[b1].angle == 270) {
                                aBullet.attack.Y -= 10;
                        }
                        bullets2.push_back(aBullet);

                    }
                }
            }
            bullets1.clear();
            bullets1 = bullets2;

            // Now Eliminating destroyed tanks  (Checked)
            for (int tn = 1; tn <= n; ++tn) {
                if (tanks[tn].alive == false) {
                    board[tanks[tn].X][tanks[tn].Y] = 0;
                }
            }


            // Now simulate commands    (Checked)
            for (int cmd = 0; cmd < actions[currentTime].size(); ++cmd) {
                anAction = actions[currentTime][cmd];

                if (tanks[anAction.tankID].alive == false) continue;
    // Action Types
    // 1 = Shoot
    // 2 = Move
    // 3 = Stop
    // 4 = Turn
                if (anAction.actionType == 1) { // (Checked)
                    newBullet.angle = tanks[anAction.tankID].angle;
                    newBullet.tankID = anAction.tankID;

                    if (tanks[anAction.tankID].angle == 0) {    // (Checked)
                        newBullet.attack.X = tanks[anAction.tankID].X + 10;
                        newBullet.attack.Y = tanks[anAction.tankID].Y;
                    }
                    else if (tanks[anAction.tankID].angle == 90) {  // (Checked)
                        newBullet.attack.X = tanks[anAction.tankID].X;
                        newBullet.attack.Y = tanks[anAction.tankID].Y + 10;
                    }
                    else if (tanks[anAction.tankID].angle == 180) { // (Checked)
                        newBullet.attack.X = tanks[anAction.tankID].X - 10;
                        newBullet.attack.Y = tanks[anAction.tankID].Y;
                    }
                    else {  // (Checked)
                        newBullet.attack.X = tanks[anAction.tankID].X;
                        newBullet.attack.Y = tanks[anAction.tankID].Y - 10;
                    }
                    bullets1.push_back(newBullet);
                }
                else if (anAction.actionType == 2) {
                    tanks[anAction.tankID].moving = true;
                    //cout << "Time: " << currentTime << " TankID: " << anAction.tankID << " cmd: MOVE Angle : " << tanks[anAction.tankID].angle << endl;
                }
                else if (anAction.actionType == 3) {
                    tanks[anAction.tankID].moving = false;
                }
                else if (anAction.actionType == 4) {
                    tanks[anAction.tankID].angle = (tanks[anAction.tankID].angle + anAction.angle + 360) % 360;
                }

            }



        }
        // Simulation Time End

        // Now Search for Ans
        int aliveTanks = 0, ans;
        for (int tn = 1; tn <= n; ++tn) {
            if (tanks[tn].alive == true) {
                ++aliveTanks;
                ans = tn;
            }
        }

        if (aliveTanks == 0 || aliveTanks > 1) {
            cout << "NO WINNER!" << endl;
        }
        else {
            //cout << ans << endl;
            cout << tanks[ans].tankName << endl;
            // map < string, int >::iterator it;
            // for (it = tankid.begin(); it != tankid.end(); ++it) {
            //     if (it->second == ans) {
            //         cout << it->first << endl;
            //         break;
            //     }
            // }
        }
    }

    return (0);
}
