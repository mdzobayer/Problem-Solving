#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

/// Store information of a suffix
struct suffix {
    int index;
    int rank[2];
};

/// Compare function to used by sort() to compare two suffixes
/// Compare two pairs, returns 1 if first pair is smaller
int cmp (suffix a, suffix b) {
    return (a.rank[0] == b.rank[0]) ? (a.rank[1] < b.rank[1] ? 1 : 0) :
                (a.rank[0] < b.rank[0] ? 1 : 0);
}

void buildSuffixArray(char *txt, int n, vector<int> &vt) {
    /// Store suffixes
    suffix suffixes[n];

    for (int i = 0; i < n; ++i) {
        suffixes[i].index = i;
        suffixes[i].rank[0] = txt[i] - 'a';
        suffixes[i].rank[1] = ((i+1) < n) ? (txt[i + 1] - 'a') : -1;
    }
    /// Sort suffix using first 2 character
    sort (suffixes, suffixes + n, cmp);

    int ind[n];

    for (int k = 4; k < 2*n; k *= 2) {
        int rank = 0;
        int prev_rank = suffixes[0].rank[0];
        suffixes[0].rank[0] = rank;
        ind[suffixes[0].index] = 0;

        /// Assigning rank to suffixes
        for (int i = 1; i < n; ++i) {

            /// If first rank and next ranks are same as that of previous
            /// suffix in array, assign the same new rank to this suffix
            if (suffixes[i].rank[0] == prev_rank && suffixes[i].rank[1] == suffixes[i - 1].rank[1]) {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = rank;
            }
            else { /// Otherwise increment rank and assign
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = ++rank;
            }
            ind[suffixes[i].index] = i;
        }

        /// Assign next rank to every suffix
        for (int i = 0; i < n; ++i) {
            int nextIndex = suffixes[i].index + k / 2;
            suffixes[i].rank[1] = (nextIndex < n) ?
                                suffixes[ind[nextIndex]].rank[0] : -1;
        }

        /// Sort the suffixes according to the first k character
        sort(suffixes, suffixes + n, cmp);
    }

    for (int i = 0; i < n; ++i) {
        vt.push_back(suffixes[i].index);
    }
}

int main() {

    vector<int> vt;
    char txt[] = "banana";
    int n = strlen(txt);
    buildSuffixArray(txt, n, vt);

    for (int i = 0; i < vt.size(); ++i) {
        printf("%d ", vt[i]);
    }
    printf("\n");

    return (0);
}
