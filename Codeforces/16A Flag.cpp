#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	int n,m;
	char c,t;
	string ans = "YES";
	cin >> n >> m;
	for (int i=0; i<n; i++){
		cin >> c;
		if (c == t) ans = "NO";
		for (int i=1; i<m; i++){
			cin >> t;
			if (t != c) ans = "NO";
		}
		t = c;
	}
	cout << ans << endl;
	return 0;
}
