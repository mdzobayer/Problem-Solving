
#include <cstdio>
#include <vector>

using namespace std;

#define SIZE 100000 + 5

int arr[SIZE];
vector < int > pArray;

int main() {
	int test, n, k, i;

	scanf("%d", &test);
	while(test --) {

		scanf("%d %d", &n, &k);
		for (i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}

		if (k > n) {
			k = k % n;
		}

		pArray.clear();

		for (i = n - k; i < n; ++i) {
			pArray.push_back(arr[i]);
		}

		for (i = 0; i < (n - k); ++i) {
			pArray.push_back(arr[i]);
		}

		printf("%d", pArray[0]);
		for (i = 1; i < n; ++i) {
			printf(" %d", pArray[i]);
		}
		printf("\n");
	}

}

