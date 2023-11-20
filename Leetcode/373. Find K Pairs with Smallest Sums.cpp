class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int index1, index2;
        vector<int> ansPair(2);
        vector<vector<int>> ans;

        set<pair<int,int>> visited;

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> minHeap;

        pair<int,pair<int,int>> triplet = make_pair(nums1[0] + nums2[0], make_pair(0, 0));
        minHeap.push(triplet);
        visited.insert(make_pair(0, 0));

        while(k > 0 && !minHeap.empty()) {

            triplet = minHeap.top();
            minHeap.pop();

            index1 = triplet.second.first;
            index2 = triplet.second.second;

            if (index1 + 1 < nums1.size() && visited.find(make_pair(index1 + 1, index2)) == visited.end()) {
                triplet = make_pair(nums1[index1 + 1] + nums2[index2], make_pair(index1 + 1, index2));
                minHeap.push(triplet);
                visited.insert(make_pair(index1 + 1, index2));
            }

            if (index2 + 1 < nums2.size() && visited.find(make_pair(index1, index2 + 1)) == visited.end()) {
                triplet = make_pair(nums1[index1] + nums2[index2 + 1], make_pair(index1, index2 + 1));
                minHeap.push(triplet);
                visited.insert(make_pair(index1, index2 + 1));
            }

            ansPair[0] = nums1[index1];
            ansPair[1] = nums2[index2];

            ans.push_back(ansPair);
            -- k;
        }

        return ans;
    }
};