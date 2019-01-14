#include <iostream>
using namespace std;
#include "ShapesAbstract.h"


Shape::Shape(color ink, int line)
	: penColor{ ink }, penWidth{ line }
{
	// shape constructor
}

//void Shape::Draw() const
//{
//	// common drawing code e.g. create a pen object
//	cout << "Drawing a ";
//	switch (penColor)
//	{
//	case color::Black:
//	{
//		cout << "Black ";
//		break;
//	}
//	case color::White:
//	{
//		cout << "White ";
//		break;
//	}
//	case color::Blue:
//	{
//		cout << "Blue ";
//		break;
//	}
//	case color::Red:
//	{
//		cout << "Red ";
//		break;
//	}
//	}
//}

Shape::~Shape()
{
	cout << "Destroying a Shape objects" << endl;
}

Rectangle::Rectangle(color ink, int line, Point topL, Point bottomR)
	: Shape(ink, line), topLeft{ topL }, bottomRight{ bottomR }
{
	// Rectangle constuctor
}


Rectangle::~Rectangle()
{
	cout << "Destroying a Rectangle objects" << endl;
}

void Rectangle::Draw() const
{
	// may need to call base class function to delegate base class operations
	Shape::Draw();
	// specific Rectangle drawing code
	cout << "Drawing a Rectangle top left " << topLeft.x << "," << topLeft.y
		<< " bottomRigh " << bottomRight.x << "," << bottomRight.y << endl;
}

Ellipse::Ellipse(color ink, int line, Point topL, int majorDiam, int minorDiam)
	: Shape(ink, line), topLeft{ topL }, majorDiameter{ majorDiam }, minorDiameter{ minorDiam }
{

}

void Ellipse::Draw() const
{
	// may need to call base class function to delegate base class operations
	Shape::Draw();
	// specific Rectangle drawing code
	cout << "Drawing a Ellipse top left " << topLeft.x << "," << topLeft.y << endl;
}

Ellipse::~Ellipse()
{
	cout << "Destroying a Ellipse objects" << endl;
}

Triangle::Triangle(Point topP, Point bottomL, Point bottomR)
	: Shape(color::Black, 0), topPoint{ topP }, bottomLeft{ bottomL }, bottomRight{ bottomR }
{
	// Triangle Constructor
};

void Triangle::Draw() const
{
	// may need to call base class function to delegate base class operations
	Shape::Draw();
	// specific Rectangle drawing code
	cout << "Drawing a Triangle top left " << topPoint.x << "," << topPoint.y
		<< " bottomRigh " << bottomRight.x << "," << bottomRight.y
		<< " BootomLeft " << bottomLeft.x << "," << bottomLeft.y << endl;
}

Triangle::~Triangle()
{
	cout << "Destroying a Triangle objects" << endl;
}