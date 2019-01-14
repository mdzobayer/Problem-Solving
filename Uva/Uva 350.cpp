#include <cstdio>
#include <map>

int main() {
    long long int z, i, m, l, count, cas = 0;
    while(scanf("%lld%lld%lld%lld", &z, &i, &m, &l) == 4) {
        if (z == 0 || i == 0 || m == 0 || l == 0)
            break;
        ++cas;
        count = 0;
        std::map<long long int, int> mp;
        while(true){
            l = ((z * l) + i) % m;
            mp[l]++;
            if(mp[l] == 2)
                break;
            ++count;
        }
        printf("Case %lld: %lld\n", cas, count);
    }
    return (0);
}
