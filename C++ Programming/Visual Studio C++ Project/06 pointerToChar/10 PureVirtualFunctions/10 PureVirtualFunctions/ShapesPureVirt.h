#pragma once

enum class color { Black, White, Red, Yellow, Blue, Green };

struct Point
{
	int x;
	int y;

};
// ------ Abstract Class --------
class Shape
{
public:
	Shape(color ink, int line);
	// ------ Pure Virtual Functions ------
	virtual void Draw() const = 0;
	~Shape();
private:
	color penColor;
	int penWidth;
};

class Rectangle : public Shape
{
public:
	Rectangle(color ink, int line, Point topL, Point bottomR);
	virtual void Draw() const;
	~Rectangle();
private:
	Point topLeft;
	Point bottomRight;
};

class Ellipse : public Shape
{
public:
	Ellipse(color ink, int line, Point topL, int majorDiam, int minorDiam);
	virtual void Draw() const;
	~Ellipse();
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
	void Draw() const;
	~Triangle();
private:
	Point topPoint;
	Point bottomLeft;
	Point bottomRight;
};
