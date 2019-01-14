#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

void DemoArray()
{
	cout << "ARRAY TEST" << endl << "===============" << endl;
	// construction uses aggregate initialization
	array<int, 3> a1{ { 1, 2, 3 } }; // double-braces required by some older compilers
	array<int, 3> a2{ { 1, 2, 3} };	 // never required after = 
	array<string, 2> a3 = { string("a"), "b" };

	// container operations are supported
	sort(a1.begin(), a1.end());
	reverse_copy(a2.begin(), a2.end(), ostream_iterator<int>(cout, " "));

	std::cout << endl;

	// ranged for loop is supported 
	for (const auto& s : a3)
	{
		cout << s << ' ';
	}
	cout << endl;
}	