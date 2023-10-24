class Solution {
public:
    long long int calculateArea(vector<int> &height, int left, int right)
    {

        int minHeight = min(height[left], height[right]);

        return (minHeight * (right - left));
    }

    int maxArea(vector<int> &height)
    {
        long long int maxArea = 0, minHeight;
        int left = 0, right = height.size() - 1;

        while (left < right)
        {

            maxArea = max(maxArea,
                        calculateArea(height, left, right));

            //cout << "maxArea = " << maxArea << " left, right " << left << " " << right << endl;

            if (height[left] < height[right])
            {
                // left secrifices his position
                ++left;
            }
            else
            {
                // right secrifices his position
                --right;
            }

        }

        return maxArea;
    }
};