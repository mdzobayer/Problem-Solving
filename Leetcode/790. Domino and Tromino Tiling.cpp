class Solution {
    int mod = 1e9 + 7;
    long long int dpN[1000+5], dpP[1000+5];
public:
    Solution() {
        memset(dpN, -1, sizeof(dpN));
        memset(dpP, -1, sizeof(dpP));

        dpP[1] = 0;
        dpP[2] = 1;

        dpN[1] = 1;
        dpN[2] = 2;
        dpN[3] = 5;
    }

    long long int numTilings(int n) {
        if (dpN[n] != -1) return dpN[n];

        dpN[n] = ((numTilings(n - 1) % mod) + (numTilings(n - 2) % mod) + (2 * generateP(n - 1)) % mod) % mod;
        
        return dpN[n];
    }

    long long int generateP(int n) {
        
        if (dpP[n] != -1) return dpP[n];

        dpP[n] = (dpP[n - 1] + numTilings(n - 2)) % mod;

        return dpP[n];
    }

};


// Overview
// The objective of this question is as follows: Count how many ways to completely fill a 2 x n board using 2 shapes (2 x 1 dominos and L shaped trominos). Note that rotation of these shapes is allowed.

// At first glance, one might consider testing every possible combination of dominos and trominos and then count the ones that completely fill the 2 x n board. This can be achieved through backtracking, where we fill the board from left to right and, at each step, we try all valid ways to place a domino or a tromino. Once the board is full or no tile will fit in the remaining space, we remove the last tile placed (backtrack) to return to the previous board state and try all of the remaining tile placement options. As you can imagine, constructing every possible board would be a time-consuming process. Furthermore, we are not actually interested in finding every possible way to completely fill the board - we are only interested in the number of ways the board can be completely filled. With this in mind, there should be a more efficient way to solve this problem. It seems like we are stuck now. What else can we do to solve this problem?

// Whenever you are not sure how to approach a problem, it is a good idea to draw out the first couple of scenarios.


// Take a close look at the above animation. Notice that for a board with width k, some of the possible tilings can directly be derived from the two previous fully covered boards as shown below.



// However, some of the possible tilings cannot be derived from previous fully covered boards directly. Instead, they must be derived from partially covered boards with a width of k-1 as shown below (e.g. a fully covered board of width k=3 can be derived from a partially covered board of width k=2).


// The above animations provide a basic idea of where the possible tilings come from for a board with width kkk. Let's find out how we can derive an algorithm from these patterns.

// Now, let's define:

// Fully covered board: All tiles on board are covered by a domino or a tromino.
// Partially covered board: Same as a fully covered board, except leave the tile in the upper-right corner (the top row of the rightmost column) uncovered. Note, a board with only the lower-right corner uncovered is also considered "partially covered." However, as we will discover soon, we do not need to keep track of which corner is uncovered because of symmetry.
// f(k)f(k)f(k): The number of ways to fully cover a board of width kkk.
// p(k)p(k)p(k): The number of ways to partially cover a board of width kkk.
// We can determine the number of ways to fully or partially tile a board of width kkk by considering every possible way to arrive at f(k)f(k)f(k) or p(k)p(k)p(k) by placing a domino or a tromino. Let's find f(k)f(k)f(k) together and then you can pause to practice by finding p(k)p(k)p(k) on your own. All of the ways to arrive at a fully tiled board of width kkk are as follows:

// From f(k−1)f(k-1)f(k−1) we can add 1 vertical domino for each tiling in a fully covered board with a width of k−1k-1k−1, as shown in the second animation.
// From f(k−2)f(k-2)f(k−2) we can add 2 horizontal dominos for each tiling in a fully covered board with a width of k−2k-2k−2, as shown in the third animation.
// Note that we don't need to add 2 vertical dominos to f(k−2)f(k-2)f(k−2), since f(k−1)f(k-1)f(k−1) will cover that case and it will cause duplicates if we count it again.
// From p(k−1)p(k-1)p(k−1) we can add an L-shaped tromino for each tiling in a partially covered board with a width of k−1k-1k−1, as shown above (in the fourth animation).
// We will multiply by p(k−1)p(k-1)p(k−1) by 2 because for any partially covered tiling, there will be a horizontally symmetrical tiling of it. For example, the animation below shows two p(k−1)p(k - 1)p(k−1) board states that are identical when reflected over the horizontal edge of the board. Logically, there must be an equal number of ways to fully tile the board from both p(k−1)p(k - 1)p(k−1) states. So rather than count the number of ways twice, we simply multiply the number of ways from one p(k−1)p(k - 1)p(k−1) state by 2.
// Summing the ways to reach f(k)f(k)f(k) gives us the following equation:

// f(k)=f(k−1)+f(k−2)+2∗p(k−1)f(k) = f(k-1) + f(k-2) + 2 * p(k-1)f(k)=f(k−1)+f(k−2)+2∗p(k−1)



// Now that we know where tilings on f(k)f(k)f(k) are coming from, how about p(k)p(k)p(k)? Can we apply the same logic and find that out? Absolutely yes!

// Take a pen and start drawing scenarios that contribute to p(4)p(4)p(4) (this is a good technique to aid critical thinking during an interview). Start by drawing p(4)p(4)p(4), remember p(4)p(4)p(4) is a board of width 4 with the first 3 columns fully covered and the last column half covered. Now, try removing a domino or a tromino to find which scenarios contribute to p(4)p(4)p(4). Notice that p(k)p(k)p(k) can come from the below scenarios:

// Adding a tromino to a fully covered board of width k−2k-2k−2 (i.e. f(k−2)f(k-2)f(k−2))
// Adding a horizontal domino to a partially covered board of width k−1k-1k−1 (i.e. p(k−1)p(k-1)p(k−1))
// Thus, we arrive at the following conclusion for p(k)p(k)p(k):

// p(k)=p(k−1)+f(k−2)p(k) = p(k-1) + f(k-2)p(k)=p(k−1)+f(k−2)


// With all this information, we are very close to our first approach - Dynamic Programming.

// Why Dynamic Programming?

// When a question asks us to minimize, maximize, or find the number of ways to do something, it doesn't always mean that dynamic programming is the best approach, but it is usually a good indicator that we should at least consider using a dynamic programming approach.

// The number of ways to reach the current state depends on the number of ways to reach the previous state. This can be seen in the functions f(k)f(k)f(k) and p(k)p(k)p(k) which depend on previous fully and partially filled boards. When using dynamic programming, these functions are called transition functions.


// Approach 1: Dynamic Programming (Top-down)
// Intuition

// In this approach, we will use the two transition functions as the recurrence relation. Then we will create a recursive solution from the top (f(n)f(n)f(n)) to the bottom (base cases described in the algorithm section) since it's generally more intuitive to solve dynamic programming problems in a top-down manner. Additionally, to avoid repeat calculations, we will memoize the result for each subproblem by storing the calculated results in two maps (f_cache and p_cache). Note that in the python implementation, this will be handled automatically by the @cache decorator.

// Algorithm

// We'll start from f(n)f(n)f(n) and then dive all the way down to the base cases, f(1)f(1)f(1), f(2)f(2)f(2), and p(2)p(2)p(2).
// Use the same definition for fff and ppp from the Overview section
// f(k)f(k)f(k): The number of ways to fully cover a board of width kkk
// p(k)p(k)p(k): The number of ways to partially cover a board of width kkk
// Recursion calls will use the results of subproblems and base cases to help us get the final result, f(n)f(n)f(n).
// The stop condition for the recursive calls is when kkk reaches a base case (i.e. k<=2k <= 2k<=2).
// Values for the base cases will be directly returned instead of making more recursive calls.
// f(1)=1f(1) = 1f(1)=1
// f(2)=2f(2) = 2f(2)=2
// p(2)=1p(2) = 1p(2)=1
// To avoid repeated computations, we will use 2 hashmaps (f_cache and p_cache) to store calculated values for fff and ppp. In Python, the built-in @cache wrapper will automatically maintain these hashmaps for us.
// If kkk is greater than 222, then we will make recursive calls to fff and ppp according to the transition function:
// f(k)=f(k−1)+f(k−2)+2∗p(k−1)f(k) = f(k-1) + f(k-2) + 2 * p(k-1)f(k)=f(k−1)+f(k−2)+2∗p(k−1)
// p(k)=p(k−1)+f(k−2)p(k) = p(k-1) + f(k-2)p(k)=p(k−1)+f(k−2)
// f(n)f(n)f(n) will be returned once all recursive calls are finished.
// Implementation