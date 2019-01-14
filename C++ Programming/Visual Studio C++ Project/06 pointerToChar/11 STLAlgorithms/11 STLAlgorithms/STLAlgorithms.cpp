#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

class Book
{
public:
	Book(string nam, string auth, int ncop)
		: name{ nam }, author{ auth }, nCopies{ ncop }
	{
		//
	}
	void Display() const
	{
		cout << "You have " << nCopies << " copies of book " << name
			<< " by " << author << endl;
	}
private:
	string name;
	string author;
	int nCopies;
};

void DumpVector(vector<int> & vec)
{
	for (int n : vec)
	{
		cout << n << " ";
	}
	cout << endl;
}

void displayBook(const Book& b)
{
	b.Display();
}

int main()
{
	vector <int> numbers{ 99, 6, 4, 3, 2, 5, 9, 8, 7 };

	sort(numbers.begin(), numbers.end());		// sort hole vector
	DumpVector(numbers);

	vector <int> numbers2{ 99, 6, 4, 3, 2, 5, 9, 8, 7 };
	vector <int>::iterator start;
	vector <int>::iterator finish;

	start = numbers2.begin();
	++start;											// start 'points to' 6
	finish = find(numbers2.begin(), numbers.end(), 8);	// finish 'points to' 8

	sort(start, finish);
	DumpVector(numbers2);

	vector <Book> library;
	library.emplace_back("Winnie the Pooh", "A. A. Milne", 5);
	library.emplace_back("Swallows and Amazons", "Arthur Ransome", 2);
	library.emplace_back("The complete works of Shakespeare", "William Shakespeare", 4);
	library.emplace_back("The Gettysburg Address", "Abraaham Lincoln", 1);
	library.emplace_back("New Britain: My Vision Of a Young Country", "Tony Blair", 5);

	for_each(library.begin(), library.end(), displayBook);	// for_each calling displayBook
															// for each member of the vector.

	for_each(library.begin(), library.end(), mem_fn(&Book::Display)); // for_each calling
																	  // Book::Display for
																	  // each member of the
																	  // vector

	return (0);
}
