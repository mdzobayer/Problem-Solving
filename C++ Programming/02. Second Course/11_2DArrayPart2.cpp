#include <iostream>

using namespace std;

int main(){

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
     cout << endl;
     for(int c = 0; c < cols; ++c){
        cout << "Test " << c + 1 << ": ";
        for(int r = 0; r < rows; ++r){
            cout << grades[r][c] << " ";
            total += grades[r][c];
        }
        average = total / rows;
        cout << "Average: " << average << endl;
        total = 0;
        average = 0.0;
     }
    return (0);
}
