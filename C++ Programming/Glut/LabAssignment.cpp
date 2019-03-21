// C program to demonstrate scaling of abjects
#include <bits/stdc++.h>
#include<stdio.h> 
#include<graphics.h> 

using namespace std; 

// Matrix Multiplication to find new Coordinates. 
// s[][] is scaling matrix. p[][] is to store 
// points that needs to be scaled. 
// p[0][0] is x coordinate of point. 
// p[1][0] is y coordinate of given point. 
void findNewCoordinate(int s[][2], int p[][1]) 
{ 
    int temp[2][1] = { 0 }; 
  
    for (int i = 0; i < 2; i++) 
        for (int j = 0; j < 1; j++) 
            for (int k = 0; k < 2; k++) 
                temp[i][j] += (s[i][k] * p[k][j]); 
  
    p[0][0] = temp[0][0]; 
    p[1][0] = temp[1][0]; 
} 
  
// Scaling the Polygon 
void scale(int x[], int y[], int sx, int sy) 
{ 
    line(x[2], y[2], x[0], y[0]); 
  
    // Initializing the Scaling Matrix. 
    int s[2][2] = { sx, 0, 0, sy }; 
    int p[2][1]; 
  
    // Scaling the triangle 
    for (int i = 0; i < 3; i++) 
    { 
        p[0][0] = x[i]; 
        p[1][0] = y[i]; 
  
        findNewCoordinate(s, p); 
  
        x[i] = p[0][0]; 
        y[i] = p[1][0]; 
    } 
  
     
    line(x[2], y[2], x[0], y[0]); 
} 
  
// Driven Program 
int main() 
{ 
    int x[5];
    int y[5];
    

    printf("Enter x1, y1, x2, y2: ");
    cin >> x[0] >> y[0] >> x[2] >> y[2];
    printf("Enter Scaling x,y: ");
    int sx = 2, sy = 2; 
    cin >> sx >> sy;

    x[1] = 0; 
    y[1] = 0;
  
    int gd, gm; 
    detectgraph(&gd, &gm); 
    initgraph(&gd, &gm," "); 
  
    scale(x, y, sx,sy); 
    getch(); 
  
    return 0; 
}
