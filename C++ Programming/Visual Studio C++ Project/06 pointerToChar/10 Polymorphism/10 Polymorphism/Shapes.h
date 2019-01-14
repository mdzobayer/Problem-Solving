#pragma once


enum class color { Black, White, Red, Yellow, Blue, Green };

struct Point
{
	int x;
	int y;

	Point(int val1, int val2)
		: x{ val1 }, y{ val2 }
	{

	}
};

class Shape
{
public:
	Shape(color ink, int line);
	virtual void Draw() const;
private:
	color penColor;
	int penWidth;
};

class Rectangle : public Shape
{
public:
	Rectangle(color ink, int line, Point topL, Point bottomR);
	//virtual void Draw() const;
private:
	Point topLeft;
	Point bottomRight;
};

class Ellipse : public Shape
{
public:
	Ellipse(color ink, int line, Point topL, int majorDiam, int minorDiam);
	//virtual void Draw() const;
private:
	Point topLeft;
	int majorDiameter;
	int minorDiameter;
};

class Triangle : public Shape
{
public:
	Triangle(Point topP, Point bottomL, Point bottomR);
	// Triangle(color ink, int line, Point top, Point botLeft, Point botRight);
	// The keyword does not need to be specified in derived classess as shown below,
	// however, there is no harm in doing so & it makes the fact that Draw() is a virtual
	// function more obvious.
	//void Draw() const;
private:
	Point topPoint;
	Point bottomLeft;
	Point bottomRight;
};