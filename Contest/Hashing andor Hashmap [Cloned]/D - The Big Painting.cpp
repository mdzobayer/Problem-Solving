#include <cstdio>
#include <cstring>

#define SIZE 2010

int hp, wp, hm, wm;

char pattern[SIZE][SIZE];
char text[SIZE][SIZE];

int patt[SIZE][SIZE], i, j;

int KMP_Algorithm() {
    int w, x, i, j, k;

    /// Preprocessing KMP array.
    for (w = 0; w < hp; ++w) {
        for (i = 1, j = 0, k = 0; i < wp; ) {
            if (pattern[w][j] == pattern[w][i]) {
                patt[w][++k] = j + 1;
                ++j;
                ++i;
            }
            else if (pattern[w][j] != pattern[w][i] && j == 0) {
                patt[w][++k] = 0;
                ++i;
            }
            else {
                j = patt[w][j - 1];
            }
        }
    }

    /// Pattern Search
    for (i = 0, j = 0, k = 0; i < wm; ) {
        if (text[w][i] == pattern[w][j]) {
            ++j;
            ++i;
        }
        else if (text[w][i] != pattern[w][j] && j == 0) {
            ++i;
            k = i;
        }
        else {
            j = patt[w][j - 1];
            k += (j+1);
        }

        if( j == wp) {
        	//cout << "pattern found at " << ( i - j ) << endl ;
        	for (x = w + 1; x < hp; ++x) {
                if (x >= hp) break;

        	}
        	j = patt[w][ j - 1 ];
		}
    }

}
bool matchNextPattern(int w, int c) {
    int i, j, k, x;
    for (i = 0, j = 0, k = 0; i < wm; ) {
        if (text[w][i] == pattern[w][j]) {
            ++j;
            ++i;
        }
        else if (text[w][i] != pattern[w][j] && j == 0) {
            ++i;
            k = i;
        }
        else {
            j = patt[w][j - 1];
            k += (j+1);
        }

        if( j == wp) {
        	//cout << "pattern found at " << ( i - j ) << endl ;
        	for (x = w + 1; x < hp; ++x) {
                if (x >= hp) break;
        	}
        	j = patt[w][ j - 1 ];
		}
    }
}

int main() {

    while(scanf("%d %d %d %d", &hp, &wp, &hm, &wm) == 4) {
        getchar();
        for (i = 0; i < hp; ++i) {
            scanf("%s", &pattern[i]);
        }
        for (i = 0; i < hm; ++i) {
            scanf("%s", &text[i]);
        }
        memset(patt, 0, sizeof(patt));
        /// Call KMP Function

    }

    return (0);
}
