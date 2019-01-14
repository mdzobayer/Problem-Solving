#include <functional>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

template<typename T> void print_queue(T& q)
{
	while (!q.empty())
	{
		cout << q.top() << " ";
		q.pop();
	}
	cout << endl;
}

void PriorityQueueTest()
{
	cout << "PRIORITYQUEU TEST" << endl << "==================" << endl;
	priority_queue<int> q;

	for (int n : {1, 8, 5, 6, 3, 4, 0, 9, 3, 2})
	{
		q.push(n);
	}
	print_queue(q);

	// the following line create a priority queue that limits access to the top element
	// of some underlying container type ( in this case a vector<int> and explicity uses
	// a function object that can compare two element values as sort keys to determine
	// their relative order in the priority_queue. In this case it uses the std::greater
	// binary predicate function. This argument is optional and the binary predicate
	// less<typename Container::value_type> is the default value. The effect of using 
	// the greater predicate is to reverse the priority order.

	priority_queue<int, vector<int>, std::greater<int> > q2;

	for (int n : {1, 8, 5, 6, 3, 4, 0, 9, 3, 2})
	{
		q2.push(n);
	}

	print_queue(q2);

	priority_queue<string> pq;		// Create a priority queue pq to store strings.
									// and initializes the queue to be empty.


	pq.push("the quick");
	pq.push("fox");
	pq.push("jumped over");
	pq.push("the lazy dog");

	// The strings are ordered inside the priority queue in lexicographic (dictionary) oder:
	// "fox", "jumped over" "the lazy dog", "the quick"
	// The lowest priority string is "fox", and the highest priority string is "the quick"

	while (!pq.empty())
	{
		const char* s = pq.top().c_str();
		cout << s << " ";
		pq.pop();
	}
	cout << endl;

}