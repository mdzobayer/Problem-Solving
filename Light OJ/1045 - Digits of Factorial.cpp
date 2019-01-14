/*
আমরা জানি, 10 based number system এ x এর ডিজিট সংখ্যা = ⌊log10x⌋+1
একইভাবে, b based number system এ x এর ডিজিট সংখ্যা = ⌊logbx⌋+1
লগারিদমের সূত্রানুসারে,
logxy=logxz×logzy
⟹logzy=logxylogxz
∴logbn=log10nlog10b

আবার, আমরা জানি,
log10(x×y×z)=log10x+log10y+log10z
যেহেতু, n!=1∗2∗3∗4∗..........∗n , অতএব,
log10(n!)=log101+log102+..........+log10n

অতএব, আমরা আগেই 106 পর্যন্ত সব সংখ্যার log এর মান বের করে অ্যারেতে রাখব ।
এরপরে, প্রতি কেসে শুধু n ও b এর মান ইনপুট নেব এবং ⌊log10nlog10b⌋+1 এর মান প্রিন্ট করে আউটপুটে দেখাব ।

*/

#include <bits/stdc++.h>

using namespace std;

double lo[1000000+5], ans;

int main() {

    int test, t, i, digit, n, base;


    for (i = 1; i <= 1000005; ++i) {
        lo[i] = lo[i-1] + log(i);
        //cout << lo[i] << " " << log(i) << endl;
    }


    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d %d", &n, &base);

        if (n == 0 || n == 1) {
            printf("Case %d: %d\n", t, 1);
        }
        else if (n == 2) {
            n = 4;
            digit = 0;

            while(n) {
                n = n / base;
                ++digit;
            }
            printf("Case %d: %d\n", t, digit);
        }
        else {
            ans = lo[n];
            digit = ceil(ans/log(base));
            printf("Case %d: %d\n", t, digit);
        }
    }

    return (0);
}
