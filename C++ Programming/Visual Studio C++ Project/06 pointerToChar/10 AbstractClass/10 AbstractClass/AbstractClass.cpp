#include <list>
using namespace std;
#include "ShapesAbstract.h"

int main() {

	Shape* aRectangle;

	aRectangle = new Rectangle(color::Black, 2, Point{ 0, 0 }, Point{ 50, 100 });

	delete aRectangle;

	Shape* aShape;

	//aShape = new Shape(color::Black, 2);

	return (0);
}