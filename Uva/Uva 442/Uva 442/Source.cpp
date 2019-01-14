#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>
#include <cctype>

using namespace std;

struct matrix {
	char ch;
	int row;
	int col;
};

int main() {
	vector<matrix> mat;
	long long int sumOfMulti;
	int n;
	string s;
	matrix z;
	scanf("%d", &n);
	while (n--) {
		cin >> z.ch;
		cin >> z.row;
		cin >> z.col;
		mat.push_back(z);
	}
	while (scanf("%s", s) != EOF) {
		int sLen = s.length();
		bool status = true;
		sumOfMulti = 0;
		stack<matrix> tempSt;
		for (int i = 0; i < sLen; i++) {
			if (s[i] == ')') {
				matrix aa, bb;
				aa = tempSt.top();
				tempSt.pop();
				bb = tempSt.top();
				tempSt.pop();
				if (bb.col == aa.row) {
					sumOfMulti += ((bb.row * bb.col) * aa.col);
					z.ch = 'x';
					z.row = bb.row;
					z.col = aa.col;
					tempSt.push(z);
				}
				else {
					status = false;
					break;
				}
			}
			else if (isalpha(s[i])) {

				for (int j = 0; j < mat.size(); j++) {
					if (mat[j].ch == s[i]) {
						z.ch = mat[j].ch;
						z.row = mat[j].row;
						z.col = mat[j].col;
						tempSt.push(z);
						break;
					}
				}
			}
		}
		if (status) {
			printf("%lld\n", sumOfMulti);
		}
		else {
			printf("error\n");
		}
		s = "";
	}
	return (0);
}
