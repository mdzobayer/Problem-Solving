#include <cstdio>
#include <algorithm>
#include <vector>
std::vector<long long int> numbers;
int main() {

    long long int temp;
    long long int Case, i, currentCost, totalCost;
    while(scanf("%lld", &Case) && Case > 0) {
        numbers.clear();
        for (i = 0; i < Case; ++i) {
            scanf("%lld", &temp);
            numbers.push_back(temp);
        }
        currentCost = totalCost = 0;
        sort(numbers.begin(), numbers.end());
        if (Case > 1) {
            currentCost = numbers[0] + numbers[1];
            totalCost += currentCost;
            for(i = 2; i < Case; ++i) {
                currentCost += numbers[i];
                totalCost += currentCost;
            }
        }
        printf("%lld\n", totalCost);
    }

    return (0);
}
