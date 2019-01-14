#include <iostream>

using namespace std;

int main(){
    /*const int rows = 2;
    const int cols = 6;
    int numbers[rows][cols];
    int temps[rows][cols] = {{87,85,94,89,88,90},
                             {79,85,75,96,48,26}};
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j)
            numbers[i][j] = 0;
    }

    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j)
            cout << temps[i][j] << " ";
        cout << endl;
    }*/
    const int rows = 5;
    const int cols = 5;
    int total = 0;
    double average = 0.0;
    int grades[rows][cols] = {{75, 82, 84, 79, 91},
                              {75, 82, 84, 79, 91},
                              {75, 82, 84, 79, 91},
                              {75, 82, 84, 79, 91},
                              {75, 82, 84, 79, 91}};
     for(int r = 0; r < rows; ++r){
        cout << "Student " << r + 1 << ": ";
        for(int c = 0; c < cols; ++c){
            cout << grades[r][c] << " ";
            total += grades[r][c];
        }
        average = total / cols;
        cout << "Average: " << average << endl;
        total = 0;
        average = 0.0;
     }
    return (0);
}
