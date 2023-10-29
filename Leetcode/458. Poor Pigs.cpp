class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int states = (minutesToTest / minutesToDie) + 1;
        int pigsNeed = ceil(log2(buckets) / log2(states));

        return pigsNeed;
    }
};

// How many states does a pig have

// If there is no time to test, i.e. minutesToTest / minutesToDie = 0,
// the pig has only one state - alive.

// If minutesToTest / minutesToDie = 1 then the pig has a time to die from the poison,
// that means that now there are two states available for the pig : alive or dead.

// One more step. If minutesToTest / minutesToDie = 2 then there are three available
// states for the pig : alive / dead after the first test / dead after the second test.

// bla

// The number of available states for the pig is states = minutesToTest / minutesToDie + 1.

// How many buckets could test x pigs with 2 available states

// One pig could test 2 buckets - let's make him drink from the bucket
// number 1 and then wait minutesToDie time. If he is alive - the
// poison is in the bucket number 2. If he is dead - the poison
// is in the bucket number 1.

// bla

// The same way two pigs could test 22=42^2 = 42 
// 2
//  =4 buckets

// bla

// bla

// Hence if one pig has two available states, x pigs could
// test 2x2^x2 
// x
//   buckets.

// How many buckets could test x pigs with s available states

// After the discussion above, the answer is quite obvious : sxs^xs 
// x
//   buckets.

// Let's consider as an example one pig with 3 states, i.e.
// s = minutesToTest / minutesToDie + 1 = 2 + 1 = 3, and show that
// he could test 3 buckets.

// bla

// bla

// Solution

// Hence the problem is to find x such that statesx≥buckets\textrm{states}^x \ge \textrm{buckets}states 
// x
//  ≥buckets,
// where x is a number of pigs, states = minutesToTest / minutesToDie + 1
// is a number of states available for each pig, and
// buckets\textrm{buckets}buckets is number of buckets.

// The solution is well known :
// x≥log⁡statesbucketsx \ge \log_{\textrm{states}}{\textrm{buckets}}x≥log 
// states
// ​
//  buckets.
// To simplify the code let's rewrite the equation with the help of
// natural logarithms :

// x≥log⁡bucketslog⁡statesx \ge \frac{\log \textrm{buckets}}{\log \textrm{states}}x≥ 
// logstates
// logbuckets
// ​
