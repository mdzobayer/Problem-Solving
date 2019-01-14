#include <deque>
#include <string>
#include <iostream>
using namespace std;

template <typename T>
ostream& operator << (ostream& s, const deque<T>& v)
{
	s.put('[');
	char comma[3] = { '\0', ' ', '\0' };
	for (const auto& e : v) {
		s << comma << e;
		comma[0] = ',';
	}
	return s << ']';
}

void DemoDeque()
{
	cout << "DEQUE TEST" << endl << "=============" << endl;
	// initialize list syntax:
	deque<string> words1{ "the" , "Frogurt", "is", "also", "curse" };
	cout << "words1: " << words1 << endl;

	// words2 == words1
	deque<string> words2(words1.begin(), words1.end());
	cout << "words2: " << words2 << endl;

	// words3 == words1
	deque<string> words3(words1);
	cout << "words3: " << words3 << endl;

	// words4 is {"Mo", "Mo", "Mo", "Mo", "M"};
	deque<string> words4(5, "Mo");
	cout << "words4: " << words4 << endl;

	deque<int> numbers;
	numbers.push_back(3);				// Add 3 onto the deque
	numbers.push_front(10);				// Add 10 to the front
	numbers.push_back(33);				// Add 33 to the end
	for (unsigned int x = 0; x < numbers.size(); ++x)
	{
		cout << numbers[x] << " ";		// Should output: 10 3 33
	}
	cout << endl;

	int m = numbers.front();			// Get item at front of queue
	numbers.pop_front();				// Remove front item from queue
	int n = numbers.back();				// Get item at back of queue
	numbers.pop_back();					// Remove back item from queue
	cout << m << " " << n << endl;		// should output 10 33
	for (unsigned int x = 0; x < numbers.size(); x++)
	{
		cout << numbers[x] << " ";		// Should output: 3
	}
	cout << endl;

}	