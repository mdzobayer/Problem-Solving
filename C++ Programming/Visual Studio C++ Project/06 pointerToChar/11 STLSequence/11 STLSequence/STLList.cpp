#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

class ShoppingItem
{
public:
	ShoppingItem() = delete;				// no default constructor
	ShoppingItem(string item, int number)	// overloaded constructor
		: shopItem{ item }, quantity{ number }
	{
		// 
	}
	string GetItem() const
	{
		return shopItem;
	}
	int GetQuantity() const
	{
		return quantity;
	}
private:
	string shopItem;
	int quantity;
};

void DemoList()
{
	cout << "LIST TEST" << endl << "==============" << endl;
	list <ShoppingItem> Shopping;		// Empty list using default constructor
										// Other overloaded constructors exist
	{
		int numbers[]{ 1, 2, 3, 4, 5 };
		vector<int> vnumbers(numbers, numbers + sizeof(numbers) / sizeof(int));
		// construct list from array
		list<int> lnumbers(numbers, numbers + sizeof(numbers) / sizeof(int));
		// construct list from vector
		list <int> lnumbers2(vnumbers.begin(), vnumbers.end());
		// ... etc
	}


	ShoppingItem item("Bread", 1);		// create item Bread

	Shopping.push_back(ShoppingItem("Beer", 24));	// add Beer to end of list
	Shopping.push_back(ShoppingItem("Milk", 1));	// add Milk to end of list
	Shopping.push_back(item);						// add Bread item to end of list
	Shopping.emplace_back("Eggs", 12);					// add Eggs constructed in place to 
													// end of list
	Shopping.push_front(ShoppingItem("Cheese", 1));	// add Cheese to front of list
	Shopping.emplace_front("Butter", 2);			// add Butter constructed in place to 
													// front of list

	for (ShoppingItem s : Shopping)
	{
		cout << s.GetQuantity() << " " << s.GetItem() << endl;
	}
	cout << endl << endl;

	list <ShoppingItem>::iterator listIter;			// Create iterator

	listIter = Shopping.begin();					// Set iterator to start of list

	++listIter;										// Increment Iterator which acts as
	++listIter;										// a smart pointer 3 times
	++listIter;

	listIter = Shopping.erase(listIter);			// Erase item at iterator (Milk)
													// erase returns iterator pointing
													// to next item after erased or end()
													// if last item erased.

	Shopping.insert(listIter, ShoppingItem("COffee", 3));// Insert Coffee before iterator

	listIter = Shopping.begin();
	while (listIter != Shopping.end())				// Display list using iterator
	{
		cout << listIter->GetQuantity() << " " << listIter->GetItem() << endl;
		++listIter;
	}

	Shopping.clear();								// Remove all items from list
}	