#pragma once
#include <iostream>
#include <string>
using namespace std;

class StockItem
{
public:
	StockItem()
		: itemName{ "Unknow" }, stockLevel{ 0 }
	{
		// default constructor
	}

	StockItem(string name, int stock)
		: itemName{ name }, stockLevel{ stock }
	{
		// overload constructor
	}

	~StockItem() = default;

	void Display() const
	{
		cout << itemName << " " << stockLevel << endl;
	}

	friend StockItem operator + (const StockItem& lhs, int rhs);
	friend StockItem operator + (int lhs, const StockItem& rhs);

private:
	string itemName;
	int stockLevel;
};

StockItem operator + (const StockItem& lhs, int rhs)
{
	StockItem temp(lhs.itemName, lhs.stockLevel + rhs);
	return temp;
}

StockItem operator + (int lhs, const StockItem& rhs)
{
	StockItem temp(rhs.itemName, rhs.stockLevel + lhs);
	return temp;
}