class Solution {
    int n, m, k;
    int mod = 1e9 + 7;
    int dp[50 + 5][100 + 5][50 + 5];
public:
    int numOfArrays(int n, int m, int k) {
        this->n = n;
        this->m = m;
        this->k = k;

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, k);
    }

    int solve(int index, int maxSoFar, int remain) {
        if (index == n) return (int)(remain == 0);

        if (remain < 0) return (0);

        if(dp[index][maxSoFar][remain] != -1) return dp[index][maxSoFar][remain];

        int ans = 0;

        for (int i = 1; i <= maxSoFar; ++i) {
            ans += (solve(index + 1, maxSoFar, remain) % mod);
            ans %= mod;
        }

        for (int i = maxSoFar + 1; i <= m; ++i) {
            ans += (solve(index + 1, i, remain - 1)) % mod;
            ans %= mod;
        }

        return dp[index][maxSoFar][remain] = ans;
    }
};

// Approach 1: Top-Down Dynamic Programming
// Intuition

// Note. For this approach, we assume that you already know the fundamentals of dynamic programming and are figuring out how to apply it to a wide range of problems, such as this one. If you are not yet at this stage, we recommend checking out our relevant Explore Card content on dynamic programming before coming back to this problem.

// Before we start solving the problem, let's carefully read the algorithm given in the problem description to try to figure out exactly what the problem is asking for. Upon careful inspection, we can deduce that the problem is asking:

// How many arrays of length n with values in the range [1, m] exist, such that you will find exactly k new maximums when traversing from left to right?

// Given the massive number of possibilities, it seems impossible to actually try to build the arrays. Can we break the problem down?

// Let's say you are currently building a candidate array. We don't need to know the exact contents of the array, but we need to know the following:

// How many elements have we placed so far? Suppose we add elements to the array in order. We can represent this with an index i that indicates the index of the next element we will place. For example, if the current array is [1, 6, 4], the next element we will place is at i = 3.

// The maximum element in the array. We can represent this with an integer maxSoFar. In the example of [1, 6, 4], we have maxSoFar = 6.

// How many remaining new maximums must we encounter before the end? We can represent this with an integer remain. In the example of [1, 6, 4], both 1 and 6 are maximums, so if we need a total of x maximums, we have remain = x - 2.

// Given a state i, maxSoFar, remain, can we come up with a recursive way to solve the problem? Let's define a function dp(i, maxSoFar, remain) that returns the number of ways to build a valid array if we have already placed i elements, the maximum element we have placed so far is maxSoFar, and we need to place remain more new maximums. Then, the answer to the original problem would be dp(0, 0, k). We start with an empty array and need to place k new maximums.

// What would our base cases be?

// If i == n, we have filled the array. The array is valid if remain == 0 and we will return 1 in that case, or 0 otherwise.
// If remain < 0, then we have placed too many new maximums. We should immediately return 0 as it is impossible to form a valid array from this point forward.
// Now that we have the base cases, how do we calculate a given state i, maxSoFar, remain? We will attempt to place a new element at index i. There are 2 possibilities:

// We place a number that is not a new maximum. How many ways are there to do this? The range of numbers we could choose from is [1, maxSoFar]. The size of this range is maxSoFar - 1 + 1 = maxSoFar. After placing a number, the next state is i + 1, maxSoFar, remain. We move to the next index, and maxSoFar and remain are unchanged since we didn't place a new maximum. Thus, the total possibilities is maxSoFar * dp(i + 1, maxSoFar, remain).
// img


// We place a number that is a new maximum. How many ways are there to do this? The range of numbers we could choose from is [maxSoFar + 1, m]. Let's say that we choose a number num from this range. The state would be i + 1, num, remain - 1. We move to the next index, maxSoFar is updated, and we placed a new maximum. We need to try all possibilities in the range [maxSoFar + 1, m].
// img


// This gives us a recursive solution. Unfortunately, this solution is too slow as many states will be visited an exponential number of times. To solve this, we will memoize our dp function. The first time we solve a state, we will save the result in memory. The next time we visit the same state, we will refer to the result we saved instead of recalculating it. Also, remember that we need to perform operations modulo 109+710^9 + 710 
// 9
//  +7 to avoid integer overflow.

// Algorithm

// All arithmetic operations should be done mod 109+710^9 + 710 
// 9
//  +7.

// Define a memoized function dp(i, maxSoFar, remain):
// If i == n, return 1 if remain == 0, and 0 otherwise.
// If remain < 0, return 0.
// Initialize ans as maxSoFar * dp(i + 1, maxSoFar, remain).
// Iterate num in the range [maxSoFar + 1, m]:
// Add dp(i + 1, num, remain - 1) to ans.
// Return ans.
// Return dp(0, 0, k), the answer to the original problem.
