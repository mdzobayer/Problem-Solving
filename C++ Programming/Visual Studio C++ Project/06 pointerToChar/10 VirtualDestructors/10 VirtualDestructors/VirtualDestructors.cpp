#include <list>
using namespace std;
#include "ShapesDestructors.h"

int main() {

	Shape* aShape;
	Shape* aRectangle;

	aShape = new Shape(color::Black, 2);
	aRectangle = new Rectangle(color::Black, 2, Point{ 0, 0 }, Point{ 50, 100 });

	delete aShape;

	delete aRectangle;

	return (0);
}