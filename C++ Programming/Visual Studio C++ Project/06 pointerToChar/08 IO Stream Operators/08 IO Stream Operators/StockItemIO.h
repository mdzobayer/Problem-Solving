#pragma once
#include <string>
#include <iostream>
using namespace std;

class StockItem
{
public:
	StockItem()
		: itemName{ "Unknown" }, stockLevel{ 0 }
	{
		// default constructor
	}

	StockItem(string name, int stock)
		: itemName{ name }, stockLevel{ stock }
	{
		// overloaded constructor
	}

	~StockItem() = default;

	string GetItemName() const
	{
		return itemName;
	}

	int GetStockLevel() const
	{
		return stockLevel;
	}

	friend istream& operator >> (istream& is, StockItem& item);
	
private:
	string itemName;
	int stockLevel;
};

istream& operator >> (istream& is, StockItem& item)
{
	is >> item.itemName >> item.stockLevel;
	return is;
}

ostream& operator << (ostream& os, const StockItem& item)
{
	os << "Item: " << item.GetItemName() << " Stock level: " << item.GetStockLevel();
	return os;
}