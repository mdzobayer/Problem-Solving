// Quincy 2005
// 150 150 100
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
	putpixel(x,y,WHITE);
	//printf("P\tX\tY");
	//printf("%d\t,%d\t,%d\n",p,x,y);
	while(x < xEnd)
	{
        x++;
        if(p<0)
            p+=twoDy;
        else{
            y++;
            p += twoDyDx;
        }
        putpixel(x,y,WHITE);
        //printf("%d\t,%d\t,%d\n",p,x,y);
	}
}


void BreasenhamCircle(int Cx, int Cy, int r)
{
    int x = 0, y = r;
    int d = 3 - (2 * r);
    BresenhamLine(Cx, Cy, Cx + x,Cy + y);
    while(x < y) {
        //DrawCircle(Cx, Cy, x, y);
        putpixel(Cx + x,Cy + y,WHITE);
//        putpixel(Cx + x,Cy - y,WHITE);
//        putpixel(Cx - x,Cy + y,WHITE);
//        putpixel(Cx - x,Cy - y,WHITE);
//
//        putpixel(Cx + y,Cy + x,RED);
//        putpixel(Cx + y,Cy - x,RED);
//        putpixel(Cx - y,Cy + x,RED);
//        putpixel(Cx - y,Cy - x,RED);

        ++x;

        if(d < 0) {
            d = d + (4 * x) + 6;
        }
        else {
            --y;
            d = d + (4 * (x - y)) + 10;
        }
        putpixel(Cx + x,Cy + y,WHITE);
//        putpixel(Cx + x,Cy - y,WHITE);
//        putpixel(Cx - x,Cy + y,WHITE);
//        putpixel(Cx - x,Cy - y,WHITE);
//
//        putpixel(Cx + y,Cy + x,RED);
//        putpixel(Cx + y,Cy - x,RED);
//        putpixel(Cx - y,Cy + x,RED);
//        putpixel(Cx - y,Cy - x,RED);

        //++x;
    }
    BresenhamLine(Cx, Cy, Cx, Cy + r);
    BresenhamLine(Cx, Cy, Cx + x,Cy + y);

}

int main()
{
    int x1, y1, x2, y2, r;
	int gdriver, gmode;

	printf("Enter the two points of the line(x, y, r):");
	scanf("%d %d %d",&x1, &y1, &r);


	gdriver = DETECT;
	initgraph(&gdriver,&gmode,"");

	BreasenhamCircle(x1,y1, r);

	getch();
	closegraph();


	return (0);
}




