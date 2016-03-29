// LeetCode problem
//

// Time limit exceeded O(n^2) solution
class Solution {
public:
    int numSquares(int n) {
        // O(n^2) solution, not very fast.
        if (n <= 0)
            return -1;
        vector<int> dp(n + 1, INT_MAX);
        for (int i = 1; i * i <= n; i++) {
            dp[i * i] = 1;
        }
        
        for (int i = 1; i <= n; i++) {
            if (dp[i] == INT_MAX) {
                for (int j = 1; j < i; j++) {
                    dp[i] = min(dp[i], dp[j] + dp[i - j]);
                }
            }
        }
        
        return dp[n];
    }
};

// O(n * sqrt(n)) solution.
// We fill the linear table with a smarter way.
class Solution {
public:
    int numSquares(int n) {
        // O(n^2) solution, not very fast.
        if (n <= 0)
            return -1;
        vector<int> dp(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            // sum of ones solution.
            // dp[0] = 0 is very important in this solution.
            dp[i] = i;
        }
        
        for (int i = 1; i * i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                // Smaller number is always updated first.
                int square = i * i;
                if (square <= j) {
                    dp[j] = min(dp[j], dp[j - square] + 1);
                }
            }
        }
        
        return dp[n];
    }
};
