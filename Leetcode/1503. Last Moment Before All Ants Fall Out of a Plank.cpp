class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int i, ans = 0;

        for (i = 0; i < left.size(); ++i) {
            ans = max(ans, left[i]);
        }

        for (i = 0; i < right.size(); ++i) {
            ans = max(ans, n - right[i]);
        }

        return ans;
    }
};

// The two scenarios are actually equivalent! That is, the collisions are completely irrelevant. Why?

// When the ants collide, they do not change position because their attempt at moving forward is blocked. What we mean here is that at t = 2, A is at index 1 and tries to walk to the right. However, it collides into B and stays at index 1. The same can be said for B remaining at position 2.

// However, the ant that they collided with is at the position that they would have been at had there not been any collision. The ant they collided with also now has their original velocity (since their velocities swapped after the collision).

// Because all the ants here are the same, we previously referred to them as A and B for better distinction. They have no differences in reality. Thus two ants colliding according to the rules and simply passing through each other are two entirely identical scenarios. If the ant they collided with has their original velocity and is at the same position they would have been at had there not been any collision (and vice-versa), did the collision really change anything? No.

// Thus, we can consider the ants walking right simply passing through those walking left. So what will be our answer?

// An ant walking left from position num will take num time to fall off the plank.
// An ant walking right from position num will take n - num time to fall off the plank.
// We simply take the maximum of all these times.