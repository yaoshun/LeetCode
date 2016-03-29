// LeetCode problem
// There is a fence with n posts, each post can be painted with one of the k colors.
//
// You have to paint all the posts such that no more than two adjacent fence posts have the same color.
//
// Return the total number of ways you can paint the fence.
//
// Note:
// n and k are non-negative integers.
//

class Solution {
public:
    int numWays(int n, int k) {
        // Understand no more than two adjacent fence have the same color.
        if (n == 0)
            return 0;
        if (n == 1)
            return k;
            
        // numWays last two fence equal. eq[i]
        // numWays last two fence nonequal. noneq[i]
        // Then eq[i] = noneq[i - 1], noneq[i] = (noneq[i - 1] + eq[i - 1]) * (k - 1)
        vector<int> eq(n + 1, 0);
        vector<int> noneq(n + 1, 0);
        
        eq[2] = k;
        noneq[2] = k * (k - 1);
        for (int i = 3; i <= n; i++) {
            // Think about the transition function from the problem requirement.
            eq[i] = noneq[i - 1];
            noneq[i] = (noneq[i - 1] + eq[i - 1]) * (k - 1);
        }
        return eq[n] + noneq[n];
    }
};
