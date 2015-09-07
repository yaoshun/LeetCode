// LeetCode hard problem
//
// There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.
//
// The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.
//
// Note:
// All costs are positive integers.
//
// Follow up:
// Could you solve it in O(nk) runtime?


// First Solution: Naive DP, O(n*k^2) complexity.
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0)
            return 0;
        int k = costs[0].size();
        if (k == 0)
            return 0;
            
        vector<vector<int>> dp(n, vector<int>(k, 0));
        for (int i = 0; i < k; i++) {
            dp[0][i] = costs[0][i];
        }
        
        // dp[i][j] = costs[i][j] + min(dp[i - 1][!=j])
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < k; j++) {
                dp[i][j] = INT_MAX;
                for (int m = 0; m < k; m++) {
                    if (m != j)
                        dp[i][j] = min(dp[i][j], costs[i][j] + dp[i - 1][m]);
                }
            }
        }
        
        int res = INT_MAX;
        for (int i = 0; i < k; i++)
            res = min(res, dp[n - 1][i]);
            
        return res;
    }
};

// To reduce the runtime to O(n*k), we need an efficient method to
// calculate the minimum excluding one index.
// The minimum excluding itself in most entries are equal to the minimum
// element excluding the minimum element which is the second minimum.
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0)
            return 0;
        int k = costs[0].size();
        if (k == 0)
            return 0;
        
        // dp[i][j] stores the optimum solution.
        // min[i][j] stores the minimum on row i excluding itself.
        vector<vector<int>> dp(n, vector<int>(k, 0));
        vector<vector<int>> minDp(n ,vector<int>(k, 0));
        
        int first = INT_MAX;
        int second = INT_MAX;
        
        for (int i = 0; i < k; i++) {
            dp[0][i] = costs[0][i];
            if (dp[0][i] < first) {
                second = first;
                first = dp[0][i];
            } else if (dp[0][i] < second) {
                second = dp[0][i];
            }
        }
        
        for (int i = 0; i < k; i++) {
            if (dp[0][i] != first) {
                minDp[0][i] = first;
            } else {
                minDp[0][i] = second;
            }
        }
        
        // dp[i][j] = costs[i][j] + min(dp[i - 1][!=j])
        // O(nk) complexity here.
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < k; j++) {
                dp[i][j] = costs[i][j] + minDp[i - 1][j];
            }
            
            first = INT_MAX;
            second = INT_MAX;
            for (int j = 0; j < k; j++) {
                if (dp[i][j] < first) {
                    second = first;
                    first = dp[i][j];
                } else if (dp[i][j] < second) {
                    second = dp[i][j];
                }
            }
            
            for (int j = 0; j < k; j++) {
                if (dp[i][j] != first) {
                    minDp[i][j] = first;
                } else {
                    minDp[i][j] = second;
                }
            }
        }
        
        int res = INT_MAX;
        for (int i = 0; i < k; i++)
            res = min(res, dp[n - 1][i]);
            
        return res;
    }
};
