#include <list>
using namespace std;
#include "ShapesPureVirt.h"

int main() {

	Shape* aRectangle;

	aRectangle = new Rectangle(color::Black, 2, Point{ 0, 0 }, Point{ 50, 100 });

	delete aRectangle;

	return (0);
}