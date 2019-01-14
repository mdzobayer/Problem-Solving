#pragma once
#include <iostream>

using namespace std;

class Transaction
{
public:
	Transaction(char ttype, double value);
	~Transaction() = default;
	double GetBalance() const;
	bool operator != (const Transaction& rhs);
	friend ostream& operator << (ostream& os, const Transaction& txn);
	
private:
	static int nextTransactionID;
	int transactionID;
	double amount;
	char transactionType;
};