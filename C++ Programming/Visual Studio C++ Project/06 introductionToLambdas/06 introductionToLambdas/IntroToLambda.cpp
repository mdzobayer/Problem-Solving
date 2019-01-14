#include <iostream>
#include <vector>
#include "CarLambda.h"
#include <algorithm>

using namespace std;

vector<CarLambda*> SelectAny(vector<CarLambda*> pool, bool(*AnySelect)(CarLambda*))
{
	vector<CarLambda*> selected;
	for (unsigned int x = 0; x < pool.size(); ++x)
	{
		if (AnySelect(pool[x]))
		{
			selected.push_back(pool[x]);
		}
	}
	return selected;
}

bool SelBlue(CarLambda* c)
{
	return (c->GetColor() == "Blue");
}
bool SelFord(CarLambda* c)
{
	return (c->GetMake() == "Ford");
}

int main() {

	vector<CarLambda*> carpool;
	vector<CarLambda*> selected;

	carpool.push_back(new CarLambda("Ford", "Fiesta", "Blue"));
	carpool.push_back(new CarLambda("Vauxhall", "Corsa", "Red"));
	carpool.push_back(new CarLambda("Ford", "Fiesta", "Green"));
	carpool.push_back(new CarLambda("Rolls Royce", "Phantom", "Silver"));
	carpool.push_back(new CarLambda("Vauxhall", "Insignia", "Black"));
	carpool.push_back(new CarLambda("Ford", "Focus", "Black"));
	carpool.push_back(new CarLambda("Renault", "Clio", "Blue"));
	carpool.push_back(new CarLambda("BMW", "Z4 Roadster", "Orange"));
	carpool.push_back(new CarLambda("Ford", "Fiesta", "Yellow"));
	carpool.push_back(new CarLambda("Vauxhall", "Corsa", "Black"));
	carpool.push_back(new CarLambda("BMW", "4 Series Convertible", "White"));
	carpool.push_back(new CarLambda("Ford", "Galaxy", "Green"));

	selected.clear();
	// Call a generic select function passing the select criteria
	// as a pointer to a function to perform the text.
	selected = SelectAny(carpool, SelBlue);
	cout << endl << "SelectAny blue cars using function pointer: " << endl;
	for (unsigned int x = 0; x < selected.size(); ++x)
	{
		cout << selected[x]->GetMake() << " " << selected[x]->GetModel() <<
			" " << selected[x]->GetColor() << endl;
	}

	selected.clear();
	// call a generic select function passing the select criteria
	// as a pointer to a function to perform the test.
	selected = SelectAny(carpool, SelFord);
	cout << endl << "SelectAny Fords using function pointer: " << endl;
	for (unsigned int x = 0; x < selected.size(); ++x)
	{
		cout << selected[x]->GetMake() << " " << selected[x]->GetModel() <<
			" " << selected[x]->GetColor() << endl;
	}

	selected.clear();
	/*
	Square Bracket in the start indicate this is a lambda expression
	The compiler can deduce the return type of the lambda expression
	by looking at it and evaluating it. I am returning the result of
	a comparetion. The compiler can deduce i am returing a boolian.
	Therefore i don't need to public keyword bool any where of this
	lambda expression.*/
	selected.SelectAny(carpool, [](CarLambda* c) {return c->GetColor() == "Blue"; });
	/*
	When i called select any this lambda expression
	actually get converted into a pointer to a function.
	It's an anonymous function rather than a named function
	*/
	cout << endl << "SelectAny blue cars using Lambda: " << endl;
	for (unsigned int x = 0; x < selected.size(); ++x)
	{
		cout << selected[x]->GetMake() << " " << selected[x]->GetModel() <<
			" " << selected[x]->GetColor() << endl;
	}

	selected.clear();
	selected.SelectAny(carpool, [](CarLambda* c) {return c->GetMake() == "Ford"; });

	cout << endl << "SelectAny Ford cars using Lambda: " << endl;
	for (unsigned int x = 0; x < selected.size(); ++x)
	{
		cout << selected[x]->GetMake() << " " << selected[x]->GetModel() <<
			" " << selected[x]->GetColor() << endl;
	}

	cout << endl << "Select blue cars using Lambda & for_each: " << endl;
	for_each(carpool.begin(), carpool.end(), [](CarLambda* c)
	{
		if (c->GetColor() == "Blue")
		{
			cout << c->GetMake() << " " << c->GetModel() <<
				" " << c->GetColor() << endl;
		}
	});

	cout << endl << "Select Ford cars using Lambda & for_each: " << endl;
	for_each(carpool.begin(), carpool.end(), [](CarLambda* c)
	{
		if (c->GetMake() == "Ford")
		{
			cout << c->GetMake() << " " << c->GetModel() <<
				" " << c->GetColor() << endl;
		}
	});

	return (0);
}


