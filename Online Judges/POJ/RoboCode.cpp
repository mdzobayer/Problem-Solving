#include <bits/stdc++.h>
#define SIZE 120+5

using namespace std;

struct tank {
    int X, Y, angle;
    bool alive, moving;
};

    // Action Types
    // 1 = Shoot
    // 2 = Move
    // 3 = Stop
    // 4 = Turn

struct Bullet {
    int time, X, Y, angle, tankid;

    bool operator < (const Bullet & b) {
        if(this->time <= b.time) {
            return true;
        }
        return false;
    }
};

struct Movement {
    int time, tankID, actionType, angle;
};

map < string , int > tankid;
tank tanks[15];
int board[SIZE][SIZE];


bool isValid(int x, int y) {
    if (x < 0 || y < 0 || x > 120 || y > 120) return false;
    return true;
}


int main() {

    int n, m, i, x, j, y, time, tn, turnAngle, currentTankID, currentTime;
    string name, order, singleCommand;

    Bullet aBullet, newBullet;
    Movement aMovement;

    while(cin >> n >> m) {
        
        if (n == 0 && m == 0) break;
        memset(board, 0, sizeof(board));

        cin.ignore(); // Ignore \n new line

        // Clear previous tank unique id
        tankid.clear();
        currentTime = 0;
        
        // Take tank information
        for (i = 1; i <= n; ++i) {
            cin >> name >> tanks[i].X >> tanks[i].Y >> tanks[i].angle;
            tankid[name] = i;
            tanks[i].alive = true;
            tanks[i].moving = false;
            board[tanks[i].X][tanks[i].Y] = i;
        }
        // Bullet Simulator
        //queue < Bullet > bullets;
        priority_queue < Bullet > bullets;

        // Take commands
        for (i = 1; i <= m; ++i) {
            getline(cin, order);

            // Remove all semicolones
            for (j = 0; j < order.size(); ++j) {
                if (order[j] == ';')
                    order[j] = ' ';
            }
            // Add order for pursing
            stringstream allCommands(order);

            // Extract all commands
            allCommands >> time;
            allCommands >> name;
            currentTankID = tankid[name];   // Getting TankID

            // Run other process from currentTime to this process time
            for (currentTime; currentTime <= time; ++currentTime) {
                // Processing Bullet
                bool flag = true;
                while(flag) {
                    aBullet = bullets.top();
                    if (aBullet.time <= currentTime) {
                        bullets.pop();
                        if (aBullet.angle == 0) {

                        }
                        else if (aBullet.angle == 90) {

                        }
                        else if (aBullet.angle == 180) {

                        }
                        else {
                            
                        }
                        
                    }
                    else flag = false;
                }
                // Process Running Tanks
                for (tn = 1; tn <= n; ++tn) {
                    if (tanks[tn].alive && tanks[tn].moving) {
                        if (tanks[tn].angle == 0) {
                            if (isValid(tanks[tn].X + 10, tanks[tn].Y)) {
                                board[tanks[tn].X][tanks[tn].Y] = 0;
                                tanks[tn].X += 10;
                                board[tanks[tn].X][tanks[tn].Y] = tn;
                            }
                        }
                        else if (tanks[tn].angle == 90) {
                            if (isValid(tanks[tn].X, tanks[tn].Y + 10)) {
                                board[tanks[tn].X][tanks[tn].Y] = 0;
                                tanks[tn].Y += 10; 
                                board[tanks[tn].X][tanks[tn].Y] = tn;
                            }
                        }
                        else if (tanks[tn].angle == 180) {
                            if (isValid(tanks[tn].X, tanks[tn].Y - 10)) {
                                board[tanks[tn].X][tanks[tn].Y] = 0;
                                tanks[tn].Y -= 10; 
                                board[tanks[tn].X][tanks[tn].Y] = tn;
                            }
                        }
                        else {
                            if (isValid(tanks[tn].X - 10, tanks[tn].Y)) {
                                board[tanks[tn].X][tanks[tn].Y] = 0;
                                tanks[tn].X -= 10; 
                                board[tanks[tn].X][tanks[tn].Y] = tn;
                            }
                        }
                    }
                }
            }

            if (tanks[currentTankID].alive == false) continue;
        
            while(allCommands >> singleCommand) {
                if(singleCommand == "TURN") {
                    allCommands >> turnAngle;
                }
                else {

                }
            }
        }
    }

    return (0);
}