#include <iostream>
#include <queue>
using namespace std;

void QueueTest()
{
	cout << "QUEUE TEST" << endl << "=============" << endl;

	queue<int> myqueue;
	int myint;

	cout << "Please enter some intergers (enter 0 to end): \n";

	do									// push some integers on to the queue
	{
		cin >> myint;
		myqueue.push(myint);
	} while (myint);

	cout << "myqueue contains: ";
	while (!myqueue.empty())			// test for empty queue
	{
		cout << ' ' << myqueue.front(); // retrieve item at front of the queue
		myqueue.pop();					// pop (remove) the item from the front of the queue 
	}
	cout << endl;

}