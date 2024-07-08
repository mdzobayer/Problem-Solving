class Solution {
public:
    int findTheWinner(int n, int k) {
        list<int> linkedList;
        list<int>::iterator it1;
        list<int>::iterator it2;
        int i, step;

        for (int i = 1; i <= n; ++i) {
            linkedList.push_back(i);
        }

        it1 = linkedList.begin();
        while(linkedList.size() > 1) {
            step = 1;

            while(step < k) {
                ++it1;
                if (it1 == linkedList.end()) {
                    it1 = linkedList.begin();
                }
                ++step;
            }

            it2 = it1;
            ++it1;
            if (it1 == linkedList.end()) {
                it1 = linkedList.begin();
            }

            linkedList.erase(it2);
        }

        return linkedList.front();
    }
};