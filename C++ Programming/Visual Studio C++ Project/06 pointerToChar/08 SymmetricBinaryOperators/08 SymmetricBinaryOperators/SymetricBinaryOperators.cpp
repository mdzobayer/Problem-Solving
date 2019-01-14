#include "StockItem.h"

int main() {
	StockItem sprockets("Sprockets", 1000);
	StockItem widgets("Widgets", 200);
	StockItem newstock1;
	StockItem newstock2;

	newstock1 = sprockets + 1000;
	newstock2 = 500 + widgets;

	sprockets.Display();
	widgets.Display();
	newstock1.Display();
	newstock2.Display();

	return (0);
};
