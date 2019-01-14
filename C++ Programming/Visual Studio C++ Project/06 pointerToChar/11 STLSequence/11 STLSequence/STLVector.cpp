#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Person
{
public:
	Person() = delete;					// Delete default constructor
	Person(string n, int a, char g)		// Overloaded Constructor
		: name{ n }, age{ a }, gender{ g }
	{
		// 
	}
private:
	string name;
	int age;
	char gender;
};

void DemoVector()
{
	cout << "VECTOR TEST" << endl << "==============" << endl;
	vector <int> example;						// Vector to store integers
	example.push_back(3);						// Add 3 onto the vector
	example.push_back(10);						// Add 10 to the end
	example.push_back(33);						// Add 33 to the end
	for (unsigned int x = 0; x < example.size(); x++)
	{
		cout << example[x] << " ";				// Should output: 3 10 33
	}
	cout << endl;
	if (!example.empty())						// Checks if empty
	{
		example.clear();						// Clears vector
	}
	vector <int> another_vector;				// Create another vector to store integers
	another_vector.push_back(10);				// Adds to end of vector
	example.push_back(10);						// Same
	if (example == another_vector)				// To show testing equality 
	{
		example.push_back(20);
	}
	for (unsigned int y = 0; y < example.size(); y++)
	{
		cout << example[y] << " ";				// Should output 10 20
	}
	cout << endl;

	vector <Person> people;						// Create another vector to store Person objects
	Person me{ "Simon", 21, 'M' };				// Create a Person
	people.push_back(me);						// Add to end of vector - This causes copying!
	people.push_back(Person("Fred", 30, 'M'));	// Add to end of vector - This causes copying!
	people.emplace_back("Wilma", 18, 'F');		// Add to end of vector. Construct in place
												// this avoids copying

	vector <int> v1(10, 99);					// Create vector of 10 elements all
												// initialised to 99
	v1.reserve(100);							// Reserve enough space for 100 elements
	v1.resize(100, 999);						// Resize to 100 filling last 90 elements
												// with 999
	v1.resize(200);								// Resize to 200 last 100 elements are
												// uninitialised
	v1.reserve(1000);							// Reserve 1000 elements
	v1.shrink_to_fit();							// Make capacity = size (save Memory)
	cout << v1.capacity() << " "				// Should output 200 200
		<< v1.size() << endl;
}