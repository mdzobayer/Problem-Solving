#include <bits/stdc++.h>

using namespace std;

struct tank {
    int coordinateX, coordinateY, angle;
    bool alive;
};

    // Action Types
    // 1 = Shoot
    // 2 = Move
    // 3 = Stop
    // 4 = Turn

struct Shoot {
    int time, direction, x, y;
};
struct Turn {
    int time, angle, x, y, tankid;
};

map < string , int > tankid;
tank tanks[15];

int main() {

    int n, m, i, x, j, y, time, turnAngle;
    string name, order, singleCommand;

    while(cin >> n >> m) {
        
        if (n == 0 && m == 0) break;

        cin.ignore(); // Ignore \n new line

        // Clear previous tank unique id
        tankid.clear();

        // Take tank information
        for (i = 1; i <= n; ++i) {
            cin >> name >> tanks[i].coordinateX >> tanks[i].coordinateY >> tanks[i].angle;
            tankid[name] = i;
            tanks[i].alive = true;
        }

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