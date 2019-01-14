#include <iostream>
#include <set>
#include <string>
#include <functional>
using namespace std;

class BigObject
{
public:
	string id;
	explicit BigObject(const string& s) : id(s) {}
	bool operator < (const BigObject& other) const
	{
		return this->id < other.id;
	}

	// Other members.....
};

inline bool operator < (const string& otherId, const BigObject& obj)
{
	return otherId < obj.id;
}

inline bool operator < (const BigObject& obj, const string& otherId)
{
	return obj.id < otherId;
}

void SetTest()
{
	cout << "SET TEST" << endl << "==============" << endl;

	set<string> s;
	cout << "Adding 'Hello' and 'World' to the set twice" << endl;

	s.insert("Hello");
	s.insert("World");
	auto ret = s.insert("Hello");
	if (!ret.second)
	{
		cout << "Insert failed, element already exixts." << endl;
	}
	s.insert("World");
	if (!ret.second)
	{
		cout << "Insert failed, element already exists." << endl;
	}

	cout << "Set contains: ";
	while (!s.empty())
	{
		cout << ' ' << *s.begin();
		s.erase(s.begin());
	}
	cout << endl;

	// The following example shows how to overload operator < in order to enable users
	// of a std::set to do lookups simply by passing in a small string that can be
	// compared to each objects's BigObject::id member. Older compilers will not support
	// this demonstration so you may need to upgrade or comment out the example.

	// The s suffix invokes string ctor. It is a C++14 user-defined
	// literal defined in <sting>
	BigObject b1{ "42F"s };
	BigObject b2{ "52F"s };
	BigObject b3{ "62F"s };
	set<BigObject, less<>> myNewSet;

	myNewSet.insert(b1);
	myNewSet.insert(b2);
	myNewSet.insert(b3);
	auto it = myNewSet.find(string("62F"));
	if (it != myNewSet.end())
	{
		cout << "myNewSet element = " << it->id << endl;
	}
	else
	{
		cout << "element not found " << endl;
	}

}
