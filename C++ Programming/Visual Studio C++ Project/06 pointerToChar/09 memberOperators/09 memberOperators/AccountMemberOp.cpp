#include "AccountMemberOp.h"

Account::Account(string accname)
	: accountName{ accname }
{
}

Account& Account::operator += (const Transaction& rhs)
{
	transactions.emplace_back(rhs);
	return *this;
}

Account Account::operator + (const Account& rhs)
{
	double balance = 0.0;
	for (unsigned int x = 0; x < rhs.transactions.size(); ++x)
	{
		balance += rhs.transactions[x].GetBalance();
	}
	for (unsigned int x = 0; x < transactions.size(); ++x)
	{
		balance += transations[x].GetBalance();
	}
	Transaction tempTransaction('D', balance);
	Account tempAcc("Grand total Balance");
	tempAcc += tempTransaction;
	return tempAcc;
}

bool Account::operator == (const Account& rhs)
{
	bool same = true;
	if (accountName != rhs.accountName)
	{
		return false;
	}
	if (transactions.size() != rhs.transactions.size())
	{
		return false;
	}
	for (unsigned int x = 0; x < transactions.size(); ++x)
	{
		if (transactions[x] != rhs.transactions[x])
		{
			same = false;
			break;
		}
	}
	return same;
}

Transaction& Account::operator [] (int index)
{
	return transactions[index];
}

ostream& operator << (ostream& os, const Account& acc)
{
	os << "Statement for account: " << acc.accountName << endl;
	for (unsigned int x = 0; x < acc.transactions.size(); ++x)
	{
		os.precision(2);
		os << fixed << acc.transactions[x];
	}
	return os;
}