// 320 320 75

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include <stdlib.h>
#include<math.h>

void BreasenhamCircle(int Cx, int Cy, int r)
{
    int x = 0, y = r;
    int d = 3 - (2 * r);

    printf("D\tX-axis\tY-axis\n");
    

    while(x < y) {
        //DrawCircle(Cx, Cy, x, y);
        putpixel(Cx + x,Cy + y,GREEN);
        printf("%d\t%d\t%d\n", d,Cx + x,Cy + y);
        putpixel(Cx + x,Cy - y,GREEN);
        printf("%d\t%d\t%d\n", d,Cx + x,Cy - y);
        putpixel(Cx - x,Cy + y,GREEN);
        printf("%d\t%d\t%d\n", d,Cx - x,Cy + y);
        putpixel(Cx - x,Cy - y,GREEN);
        printf("%d\t%d\t%d\n", d,Cx - x,Cy - y);

        putpixel(Cx + y,Cy + x,GREEN);
        printf("%d\t%d\t%d\n", d,Cx + y,Cy + x);
        putpixel(Cx + y,Cy - x,GREEN);
        printf("%d\t%d\t%d\n", d,Cx + y,Cy - x);
        putpixel(Cx - y,Cy + x,GREEN);
        printf("%d\t%d\t%d\n", d,Cx - y,Cy + x);
        putpixel(Cx - y,Cy - x,GREEN);
        printf("%d\t%d\t%d\n", d,Cx - y,Cy - x);

        ++x;

        if(d < 0) {
            d = d + (4 * x) + 6;
        }
        else {
            --y;
            d = d + (4 * (x - y)) + 10;
        }
        //DrawCircle(Cx, Cy, x, y);
        putpixel(Cx + x,Cy + y,GREEN);
        printf("%d\t%d\t%d\n", d,Cx + x,Cy + y);
        putpixel(Cx + x,Cy - y,GREEN);
        printf("%d\t%d\t%d\n", d,Cx + x,Cy - y);
        putpixel(Cx - x,Cy + y,GREEN);
        printf("%d\t%d\t%d\n", d,Cx - x,Cy + y);
        putpixel(Cx - x,Cy - y,GREEN);
        printf("%d\t%d\t%d\n", d,Cx - x,Cy - y);

        putpixel(Cx + y,Cy + x,GREEN);
        printf("%d\t%d\t%d\n", d,Cx + y,Cy + x);
        putpixel(Cx + y,Cy - x,GREEN);
        printf("%d\t%d\t%d\n", d,Cx + y,Cy - x);
        putpixel(Cx - y,Cy + x,GREEN);
        printf("%d\t%d\t%d\n", d,Cx - y,Cy + x);
        putpixel(Cx - y,Cy - x,GREEN);
        printf("%d\t%d\t%d\n", d,Cx - y,Cy - x);

        //++x;
    }
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




