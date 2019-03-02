#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int cost[25][5], n, dp[25][5];

int solve(int index, int pre) {

	if(index >= n) return 0;

	if(dp[index][pre] != -1) return dp[index][pre];

	int minCost = INT_MAX, tmp = INT_MAX, i;

	for (i = 1; i < 4; ++i) {
		if(i != pre) {
			tmp = solve(index + 1, i) + cost[index][i];
		}
		minCost = min(minCost, tmp);
	}

	return dp[index][pre] = minCost;
}


int main() {

	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

    int result;
	int test, t, i;
	scanf("%d", &test);
	for (t = 1; t <= test; ++t) {
		scanf("%d", &n);
		for (i = 0; i < n; ++i) {
			scanf("%d %d %d", &cost[i][1], &cost[i][2], &cost[i][3]);
			//printf("index = %d %d %d %d\n", i, cost[i][1], cost[i][2], cost[i][3]);
		}
		memset(dp, -1, sizeof(dp));
		result = solve(0, 0);
		printf("Case %d: %d\n", t, result);
		//memset(cost, 0, sizeof(cost));
	}

	return 0;
}
