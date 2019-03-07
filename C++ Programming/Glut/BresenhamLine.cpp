#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include <stdlib.h>
#include<math.h>

void BresenhamLine(int xa,int ya,int xb,int yb)
{
	int dx = abs(xb-xa), dy = abs(yb-ya);
	int p = 2*dy-dx;
	int twoDy = 2*dy;
	int twoDyDx = 2 * (dy-dx);
	int x,y,xEnd;
	if(xa>xb){
        x=xb;
        y=yb;
        xEnd=xa;
	}
	else{
        x=xa;
        y=ya;
        xEnd=xb;
	}
	putpixel(x,y,GREEN);
	printf("P\tX\tY");
	printf("%d\t,%d\t,%d\n",p,x,y);
	while(x < xEnd)
	{
        x++;
        if(p<0)
            p+=twoDy;
        else{
            y++;
            p += twoDyDx;
        }
        putpixel(x,y,GREEN);
        printf("%d\t,%d\t,%d\n",p,x,y);
	}
}



int main()
{

	int gdriver,gmode;
	float x1,y1,x2,y2;

	printf("Enter the two points of the line(x1,y1,x2,y2) : ");
	scanf("%f%f%f%f",&x1, &y1, &x2, &y2);


	gdriver = DETECT;
	initgraph(&gdriver,&gmode,"");

	BresenhamLine(x1,y1,x2,y2);

	getch();
	closegraph();


	return (0);
}



