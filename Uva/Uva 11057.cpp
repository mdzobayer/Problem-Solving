#include <cstdio>
#include <vector>
using namespace std;

class multiSolu{
public:
    long long int num1, num2;
    multiSolu(long long int n1, long long int n2)
        : num1(n1), num2(n2) {};

};

int main() {

    int n;
    vector<int> multiSolution;
    long long int price[10010], money;
    while(scanf("%d", &n) == 1) {
        for(int i = 0; i < n; i++) {
            scanf("%lld", &price[i]);
        }
        scanf("%lld", &money);
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((price[i] + price[j] == money)) {
                    //printf("Peter should buy books whose prices are %lld and %lld.\n", price[j], price[i]);
                    //goto jump;
                    multiSolution.push_back(price[i]);
                    multiSolution.push_back(price[j]);
                }
            }
        }
        for ()

    }

    return (0);
}
