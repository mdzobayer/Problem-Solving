class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> hashMap;
        vector<pair<int,int>> nums;

        int n = arr.size(), i;
        for (i = 0; i < n; ++i) {
            ++ hashMap[arr[i]];
        }

        for (auto it = hashMap.begin(); it != hashMap.end(); ++it) {
            nums.push_back(make_pair(it->second, it->first));
        }

        sort(nums.begin(), nums.end());

        for (i = 0; i < nums.size(); ++i) {
            if (nums[i].first > k) {
                break;
            }
            else if (nums[i].first == k) {
                ++ i;
                break;
            }
            else {
                k -= nums[i].first;
            }
        }

        return nums.size() - i;
    }
};