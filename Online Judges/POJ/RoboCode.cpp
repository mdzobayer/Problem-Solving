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

//    bool operator <= (const Bullet & b) {
//        if(this->time <= b.time) {
//            return true;
//        }
//        return false;
//    }
};
//bool operator < (const Bullet & a, const Bullet & b) {
//    if(a.time <= b.time) {
//            return true;
//        }
//        return false;
//}

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

    freopen("in.txt", "r", stdin);

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
        queue < Bullet > bullets;
        //priority_queue < Bullet > bullets;

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
                while(flag && !bullets.empty()) {
                    aBullet = bullets.front();
                    if (aBullet.time <= currentTime) {
                        bullets.pop();

                        if (aBullet.angle == 0) {
                            if (isValid(aBullet.X - 10, aBullet.Y)) {
                                if (board[aBullet.X - 10][aBullet.Y] == 0) {
                                    if (board[aBullet.X][aBullet.Y] == 0) {
                                        // No Obstacle
                                        if (isValid(aBullet.X + 20, aBullet.Y)) {
                                            newBullet = aBullet;
                                            newBullet.X += 20;
                                            newBullet.time += 1;
                                            bullets.push(newBullet);
                                        }
                                        else if (isValid(aBullet.X + 10, aBullet.Y)) {
                                            newBullet = aBullet;
                                            newBullet.X += 10;
                                            newBullet.time += 1;
                                            bullets.push(newBullet);
                                        }
                                    }
                                    // Obstacle Found
                                    else {
                                        //board[aBullet.X][aBullet.Y] = 0;
                                        tanks[aBullet.tankid].alive = false;
                                    }
                                }
                                // Obstacle Found
                                else if(board[aBullet.X - 10][aBullet.Y] != aBullet.tankid){
                                    //board[aBullet.X - 10][aBullet.Y] = 0;
                                    tanks[aBullet.tankid].alive = false;
                                }
                            }
                        }
                        else if (aBullet.angle == 90) {
                            if (isValid(aBullet.X, aBullet.Y - 10)) {
                                if (board[aBullet.X][aBullet.Y - 10] == 0) {
                                    if (board[aBullet.X][aBullet.Y] == 0) {
                                        // No Obstacle
                                        if (isValid(aBullet.X, aBullet.Y + 20)) {
                                            newBullet = aBullet;
                                            newBullet.Y += 20;
                                            newBullet.time += 1;
                                            bullets.push(newBullet);
                                        }
                                        else if (isValid(aBullet.X, aBullet.Y + 10)) {
                                            newBullet = aBullet;
                                            newBullet.Y += 10;
                                            newBullet.time += 1;
                                            bullets.push(newBullet);
                                        }
                                    }
                                    // Obstacle Found
                                    else {
                                        //board[aBullet.X][aBullet.Y] = 0;
                                        tanks[aBullet.tankid].alive = false;
                                    }
                                }
                                // Obstacle Found
                                else if(board[aBullet.X][aBullet.Y - 10] != aBullet.tankid){
                                    //board[aBullet.X][aBullet.Y - 10] = 0;
                                    tanks[aBullet.tankid].alive = false;
                                }
                            }
                        }
                        else if (aBullet.angle == 180) {
                            if (isValid(aBullet.X + 10, aBullet.Y)) {
                                if (board[aBullet.X + 10][aBullet.Y] == 0) {
                                    if (board[aBullet.X][aBullet.Y] == 0) {
                                        // No Obstacle
                                        if (isValid(aBullet.X - 20, aBullet.Y)) {
                                            newBullet = aBullet;
                                            newBullet.X -= 20;
                                            newBullet.time += 1;
                                            bullets.push(newBullet);
                                        }
                                        else if (isValid(aBullet.X - 10, aBullet.Y)) {
                                            newBullet = aBullet;
                                            newBullet.X -= 10;
                                            newBullet.time += 1;
                                            bullets.push(newBullet);
                                        }
                                    }
                                    // Obstacle Found
                                    else {
                                        //board[aBullet.X][aBullet.Y] = 0;
                                        tanks[aBullet.tankid].alive = false;
                                    }
                                }
                                // Obstacle Found
                                else if(board[aBullet.X + 10][aBullet.Y] != aBullet.tankid){
                                    //board[aBullet.X + 10][aBullet.Y] = 0;
                                    tanks[aBullet.tankid].alive = false;
                                }
                            }
                        }
                        else {
                            if (isValid(aBullet.X, aBullet.Y + 10)) {
                                if (board[aBullet.X][aBullet.Y + 10] == 0) {
                                    if (board[aBullet.X][aBullet.Y] == 0) {
                                        // No Obstacle
                                        if (isValid(aBullet.X, aBullet.Y - 20)) {
                                            newBullet = aBullet;
                                            newBullet.Y -= 20;
                                            newBullet.time += 1;
                                            bullets.push(newBullet);
                                        }
                                        else if (isValid(aBullet.X, aBullet.Y - 10)) {
                                            newBullet = aBullet;
                                            newBullet.Y -= 10;
                                            newBullet.time += 1;
                                            bullets.push(newBullet);
                                        }
                                    }
                                    // Obstacle Found
                                    else {
                                        //board[aBullet.X][aBullet.Y] = 0;
                                        tanks[aBullet.tankid].alive = false;
                                    }
                                }
                                // Obstacle Found
                                else if(board[aBullet.X][aBullet.Y + 10] != aBullet.tankid){
                                    //board[aBullet.X][aBullet.Y + 10] = 0;
                                    tanks[aBullet.tankid].alive = false;
                                }
                            }
                        }

                    }
                    else flag = false;
                }

                // Obstacle Remove from board
                for (tn = 1; tn <= n; ++tn) {
                    if (tanks[tn].alive == false) {
                        board[tanks[tn].X][tanks[tn].Y] = 0;
                    }
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
                    tanks[currentTankID].angle = (tanks[currentTankID].angle + turnAngle + 360) % 360;
                }
                else if(singleCommand == "STOP") {
                    tanks[currentTankID].moving = false;
                }
                else if(singleCommand == "MOVE") {
                    tanks[currentTankID].moving = true;
                }
            }
        }
        {
            for (currentTime; !bullets.empty(); ++currentTime) {
                // Processing Bullet
                bool flag = true;
                while(flag && !bullets.empty()) {
                    aBullet = bullets.front();
                    if (aBullet.time <= currentTime) {
                        bullets.pop();

                        if (aBullet.angle == 0) {
                            if (isValid(aBullet.X - 10, aBullet.Y)) {
                                if (board[aBullet.X - 10][aBullet.Y] == 0) {
                                    if (board[aBullet.X][aBullet.Y] == 0) {
                                        // No Obstacle
                                        if (isValid(aBullet.X + 20, aBullet.Y)) {
                                            newBullet = aBullet;
                                            newBullet.X += 20;
                                            newBullet.time += 1;
                                            bullets.push(newBullet);
                                        }
                                        else if (isValid(aBullet.X + 10, aBullet.Y)) {
                                            newBullet = aBullet;
                                            newBullet.X += 10;
                                            newBullet.time += 1;
                                            bullets.push(newBullet);
                                        }
                                    }
                                    // Obstacle Found
                                    else {
                                        //board[aBullet.X][aBullet.Y] = 0;
                                        tanks[aBullet.tankid].alive = false;
                                    }
                                }
                                // Obstacle Found
                                else if(board[aBullet.X - 10][aBullet.Y] != aBullet.tankid){
                                    //board[aBullet.X - 10][aBullet.Y] = 0;
                                    tanks[aBullet.tankid].alive = false;
                                }
                            }
                        }
                        else if (aBullet.angle == 90) {
                            if (isValid(aBullet.X, aBullet.Y - 10)) {
                                if (board[aBullet.X][aBullet.Y - 10] == 0) {
                                    if (board[aBullet.X][aBullet.Y] == 0) {
                                        // No Obstacle
                                        if (isValid(aBullet.X, aBullet.Y + 20)) {
                                            newBullet = aBullet;
                                            newBullet.Y += 20;
                                            newBullet.time += 1;
                                            bullets.push(newBullet);
                                        }
                                        else if (isValid(aBullet.X, aBullet.Y + 10)) {
                                            newBullet = aBullet;
                                            newBullet.Y += 10;
                                            newBullet.time += 1;
                                            bullets.push(newBullet);
                                        }
                                    }
                                    // Obstacle Found
                                    else {
                                        //board[aBullet.X][aBullet.Y] = 0;
                                        tanks[aBullet.tankid].alive = false;
                                    }
                                }
                                // Obstacle Found
                                else if(board[aBullet.X][aBullet.Y - 10] != aBullet.tankid){
                                    //board[aBullet.X][aBullet.Y - 10] = 0;
                                    tanks[aBullet.tankid].alive = false;
                                }
                            }
                        }
                        else if (aBullet.angle == 180) {
                            if (isValid(aBullet.X + 10, aBullet.Y)) {
                                if (board[aBullet.X + 10][aBullet.Y] == 0) {
                                    if (board[aBullet.X][aBullet.Y] == 0) {
                                        // No Obstacle
                                        if (isValid(aBullet.X - 20, aBullet.Y)) {
                                            newBullet = aBullet;
                                            newBullet.X -= 20;
                                            newBullet.time += 1;
                                            bullets.push(newBullet);
                                        }
                                        else if (isValid(aBullet.X - 10, aBullet.Y)) {
                                            newBullet = aBullet;
                                            newBullet.X -= 10;
                                            newBullet.time += 1;
                                            bullets.push(newBullet);
                                        }
                                    }
                                    // Obstacle Found
                                    else {
                                        //board[aBullet.X][aBullet.Y] = 0;
                                        tanks[aBullet.tankid].alive = false;
                                    }
                                }
                                // Obstacle Found
                                else if(board[aBullet.X + 10][aBullet.Y] != aBullet.tankid){
                                    //board[aBullet.X + 10][aBullet.Y] = 0;
                                    tanks[aBullet.tankid].alive = false;
                                }
                            }
                        }
                        else {
                            if (isValid(aBullet.X, aBullet.Y + 10)) {
                                if (board[aBullet.X][aBullet.Y + 10] == 0) {
                                    if (board[aBullet.X][aBullet.Y] == 0) {
                                        // No Obstacle
                                        if (isValid(aBullet.X, aBullet.Y - 20)) {
                                            newBullet = aBullet;
                                            newBullet.Y -= 20;
                                            newBullet.time += 1;
                                            bullets.push(newBullet);
                                        }
                                        else if (isValid(aBullet.X, aBullet.Y - 10)) {
                                            newBullet = aBullet;
                                            newBullet.Y -= 10;
                                            newBullet.time += 1;
                                            bullets.push(newBullet);
                                        }
                                    }
                                    // Obstacle Found
                                    else {
                                        //board[aBullet.X][aBullet.Y] = 0;
                                        tanks[aBullet.tankid].alive = false;
                                    }
                                }
                                // Obstacle Found
                                else if(board[aBullet.X][aBullet.Y + 10] != aBullet.tankid){
                                    //board[aBullet.X][aBullet.Y + 10] = 0;
                                    tanks[aBullet.tankid].alive = false;
                                }
                            }
                        }

                    }
                    else flag = false;
                }

                // Obstacle Remove from board
                for (tn = 1; tn <= n; ++tn) {
                    if (tanks[tn].alive == false) {
                        board[tanks[tn].X][tanks[tn].Y] = 0;
                    }
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
        }
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
