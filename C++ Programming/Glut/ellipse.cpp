/*

250 200 0 360 100 50

*/
#include <graphics.h> 
#include <bits/stdc++.h>

using namespace std;

int main() 
{ 
 
    int gd = DETECT, gm; 
  
    int x = 250; 
    int y = 250; 
  

    int start_angle = 155; 
    int end_angle = 300; 

    int xRadius = 100;
    int yRadius = 100; 

    printf("Enter x,y,startAngle,endAngle,xRadius,yRadius: ");
    cin >> x >> y >> start_angle >> end_angle >> xRadius >> yRadius;
  
    initgraph(&gd, &gm, ""); 

    ellipse(x, y, start_angle, end_angle, xRadius, yRadius); 
  
    getch(); 
  

    closegraph(); 
  
    return 0; 
}
