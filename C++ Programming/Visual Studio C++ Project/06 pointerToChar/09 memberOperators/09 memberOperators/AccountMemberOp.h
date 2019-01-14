#pragma once
#include "TransactionMemberOp.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Account
{
public:
	Account() = default;
	Account(string accname);
	~Account() = default;
	Account operator += (const Transaction& rhs);
	Account operator + (const Account& rhs);
	bool operator == (const Account& rhs);
	Transaction& operator [] (int index);
	friend ostream& operator << (ostream& os, const Account& acc);

private:
	string accountName;
};
