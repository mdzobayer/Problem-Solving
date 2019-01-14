#include "TransactionMemberOp.h"
#include "AccountMemberOp.h"

int main() {

	Account BillGates("Bill Gates");
	Account LaurenePowellJobs("Laurene Powell Jobs");
	Transaction t1('D', 5000.0);
	Transaction t2('W', -1000.0);
	Transaction t3('D', 5000.50);
	Transaction t4('W', -1000.0);
	Transaction t5('D', 10000.99);
	Transaction t6('W', -1000.0);

	BillGates += t1; BillGates.operator += (t1);
	BillGates += t2;
	BillGates += t3;
	LaurenePowellJobs += t4;
	LaurenePowellJobs += t5;
	LaurenePowellJobs += t6;

	cout << BillGates;
	cout << LaurenePowellJobs;

	Account TotalBalance;
	TotalBalance = BillGates + LaurenePowellJobs;

	cout << TotalBalance;

	if (BillGates == BillGates)
	{
		cout << "BillGates == BillGates" << endl;
	}
	else
	{
		cout << "BillGates != BillGates" << endl;
	}
	if (BillGates == LaurenePowellJobs)
	{
		cout << "BillGates == LaurenePowellJobs" << endl;
	}
	else
	{
		cout << "BillGates != LaurenePowellJobs" << endl;
	}

	return (0);
}