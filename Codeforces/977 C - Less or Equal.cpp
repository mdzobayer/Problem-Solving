#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 //Compiler version g++ 6.3.0

 int main()
 {
 	ll i, n, x, k, cnn = 0;
 	
 	map <ll, int> mp;
 	
 	cin >> n >> k;
 	for (i = 0; i < n; ++i){
 		cin >> x;
 		mp[x] += 1;
 	}
 	
 	auto it = mp.begin();
 	for (it; it != mp.end(); ++it){
 		cnn += it->second;
 		
 		if(cnn >= k){
 			x = it->first;
 			break;
 		}
 	}
 	
 	int fs = mp.begin()->first;
 
 
 	if (cnn == k){
 		cout << x << endl;
 	}
 	else if (k == 0 && fs > 1){
 		cout << 1 << endl;
 	}
 	else {
 		cout << -1 << endl;
 	}
 	
 	return 0;
 }