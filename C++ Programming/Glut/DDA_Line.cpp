#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include <stdlib.h>
#include<math.h>

int Round(float a){
    return (a+0.5);
}
void lineDDA(int xa,int ya,int xb,int yb)
{
	int dx=xb-xa, dy=yb-ya, steps, k;
	float xinc, yinc, x=xa,y=ya;

	if(abs(dx)>abs(dy))steps=abs(dx);
	else {
        steps=abs(dy);
	}
    xinc = dx / (float)steps;
    yinc = dy / (float)steps;

	putpixel(Round(x),Round(y),RED);

	k = 0;
    while (k < steps){
        x += xinc;
        y += yinc;
        putpixel(Round(x),Round(y),RED);
        ++k;
    }
}

int main()
{
    float x1,y1,x2,y2;
	int gdriver, gmode;

	printf("Enter the two points of the line(x1,y1,x2,y2):");
	scanf("%f%f%f%f",&x1, &y1, &x2, &y2);


	gdriver = DETECT;
	initgraph(&gdriver,&gmode,"");

	lineDDA(x1,y1,x2,y2);

	getch();
	closegraph();


	return (0);
}




