#include <cstdio>
#include <cmath>

int main() {
	
	long long int t, n, x, k, sumN, sumX, sumK;
	
	scanf("%lld", &t);
	for (int i = 1; i <= t; ++i) {
		scanf("%lld %lld %lld", &n, &k, &x);
		sumN = ((n * n) + n) / 2;
		sumX = ((x-1)*(x-1) + (x - 1)) / 2;
		sumK = (((x+ k -1)*(x+ k -1)) + (x + k - 1)) / 2;
		sumN = sumN - sumK + sumX;
		printf("Case %d: %lld\n", i, sumN);
	}
	
	return (0);	
}