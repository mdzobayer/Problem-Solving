#include <bits/stdc++.h>

using namespace std;

int post[100000+5], position[100000+5], MIN[100000+5], MAX[100000+5];

int main() {

    int n, m, i, likes, x, postPos;
    scanf("%d %d", &n, &m);

    for (i = 0; i <= n+2; ++i) {
        post[i] = i;
        position[i]= i;
        MIN[i] = i;
        MAX[i] = i;
    }

    for (i = 0; i < m; ++i) {
        scanf("%d", &likes);

        postPos = position[likes];

        // update post position
        if (postPos > 1) {
            x = post[postPos - 1];
            post[postPos - 1] = likes;
            post[postPos] = x;

            // update index
            position[likes] = postPos - 1;
            position[x] = postPos;

            // update min 
            if (MIN[likes] > position[likes]) {
                MIN[likes] = position[likes];
            }
            if (MIN[x] > position[x]) {
                MIN[x] = position[x];
            }

            // update max 
            if (MAX[likes] < position[likes]) {
                MAX[likes] = position[likes];
            }
            if (MAX[x] < position[x]) {
                MAX[x] = position[x];
            }

        }
    }

    for (i = 1; i <= n; ++i) {
        printf("%d %d\n", MIN[i], MAX[i]);
    }


    return (0);
}