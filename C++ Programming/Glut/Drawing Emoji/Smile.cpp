#include <graphics.h>
#include <conio.h>

int main()
{

	int graphicdriver = DETECT, graphicmode;

	// calling initgraph function with 
	initgraph(&graphicdriver,&graphicmode,"c:\\turboc3\\bgi");

	// Printing message for user
	// outtextxy(10, 10 + 10, "A smiley face in C++ graphics");
	
	
	// Drawing Face with GREEN color 
	setcolor(CYAN);					// Setting Color GREEN
	circle(300, 100, 40);				
	setfillstyle(SOLID_FILL, CYAN);	// Making Solid color, otherwise white
	floodfill(300, 100, CYAN);

	//setting color to black
	setcolor(BLACK);
	setfillstyle(SOLID_FILL, BLACK);

	// Drawing Eyes
	fillellipse(310, 85, 2, 6);		// Right Eyes
	fillellipse(290, 85, 2, 6);		// Left Eyes

	// Drawing Mouth
	ellipse(300, 100, 205, 335, 20, 7);
	ellipse(300, 100, 205, 335, 20, 8);
	ellipse(300, 100, 205, 335, 20, 9);
	ellipse(300, 100, 205, 335, 20, 10);
	ellipse(300, 100, 205, 335, 20, 11);


	getch();
	return 0;	
}

