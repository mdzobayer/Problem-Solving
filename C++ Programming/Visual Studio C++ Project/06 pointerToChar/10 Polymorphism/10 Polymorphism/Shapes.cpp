#include <iostream>
using namespace std;
#include "Shapes.h"

Shape::Shape(color ink, int line)
	: penColor{ ink }, penWidth{ line }
{
	// shape constructor
}

void Shape::Draw() const
{
	// common drawing code e.g. create a pen object
	cout << "Drawing a ";
	switch (penColor)
	{
	case color::Black:
	{
		cout << "Black ";
		break;
	}
	case color::White:
	{
		cout << "White ";
		break;
	}
	case color::Blue:
	{
		cout << "Blue ";
		break;
	}
	case color::Red:
	{
		cout << "Red ";
		break;
	}
	}
}

Rectangle::Rectangle(color ink, int line, Point topL, Point bottomR)
	: Shape(ink, line), topLeft{  }, bottomRight{  }
{

}

Ellipse::Ellipse(color ink, int line, Point topL, int majorDiam, int minorDiam)
	: Shape(ink, line), topLeft{}, majorDiameter{ majorDiam }, minorDiameter{ minorDiam }
{

}

Triangle::Triangle(Point topP, Point bottomL, Point bottomR)
	: topPoint{ topP  }, bottomLeft{ bottomL  }, bottomRight{ bottomR }
{

}