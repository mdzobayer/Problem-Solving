#include <graphics.h> 
#include <bits/stdc++.h>

using namespace std;

int main() 
{ 
 
    int gd = DETECT, gm; 
  
    int x1, x2, y1, y2, x, y;
    printf("Enter Initial Line x1, y1, x2, y2: ");
    cin >> x1 >> y1 >> x2 >> y2;
    printf("Enter Translating point x,y: ");
    cin >> x >> y;
  
    initgraph(&gd, &gm, ""); 

    line(x1, y1, x2, y2);

    x1 += x;
    y1 += y;
    x2 += x;
    y2 += y;

    line(x1, y1, x2, y2);
  
    getch(); 
  

    closegraph(); 
  
    return 0; 
}
