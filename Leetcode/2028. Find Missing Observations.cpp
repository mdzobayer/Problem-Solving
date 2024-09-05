class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;

        for (int item : rolls) {
            sum += item;
        }

        int remainingSum = mean * (n + rolls.size()) - sum;
        
        if (remainingSum > 6 * n || remainingSum < n) {
            return vector<int>();
        }

        int distributeMean = remainingSum / n;
        int mod = remainingSum % n;

        vector<int> nElements(n, distributeMean);
        for (int i = 0; i < mod; ++i) {
            ++ nElements[i];
        }

        return nElements;
    }
};

/*

Approach: Math
Intuition
In this problem, we have some dice throw results but lost n of them. We know the results of m throws and the average value of all m + n throws. Our goal is to determine if we can find the missing throws that fit these conditions.

The mean is the sum of observations divided by the number of observations. Therefore, we can find the total sum by multiplying the mean by m + n. Next, we subtract the sum of the m known throws from this total sum to get the sum of the missing n throws.

For example:
rolls=[3,2,4,3],mean=4,n=2
totalobservations=m+n=4+2=6
sumofobservations=4∗6=24
sumofgivendicerolls=6∗2=12
sumofremainingdicerolls=24−12=12

To check if this sum is possible, we note that the minimum sum for n dice is n (if all dice show 1), and the maximum sum is 6n (if all dice show 6). So, the sum of the missing throws must be between n and 6n, inclusive.

Finally, we need to distribute this sum among the n missing throws. Ideally, each missing throw would have a value close to the average. If the sum isn’t exactly divisible by n, we distribute the remainder among the throws, making sure each value stays between 1 and 6.

Algorithm
Create an integer variable sum and set it to 0.
Calculate the sum of rolls:
Iterate through each element in rolls:
Add the current element to sum.
Compute remainingSum as mean * (n + rolls.size()) - sum.
Check the validity of remainingSum:
If remainingSum > 6 * n or remainingSum < n, return an empty list [].
Compute distributeMean as remainingSum / n and mod as remainingSum % n.
Initialize an array nElements of size n with each element set to distributeMean.
Iterate through the first mod elements of nElements:
Increment each of these elements by 1.
Return nElements as the final result.

*/