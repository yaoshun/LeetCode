
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<int> psum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            psum[i + 1] = psum[i] + nums[i];
        }
        
        // dp[i][j] represents split 0 to j into i parts.
        vector<vector<int>> dp(m + 1, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[1][i] = psum[i + 1];
        }
        
        for (int i = 2; i <= m; i++) {
            for (int j = 0; j < n; j++) {
                int k = 0;
                int a = dp[i - 1][j - 1];
                int b = psum[j + 1] - psum[j];
                dp[i][j] = max(a, b);
                while (a > b) {
                    k++;
                    a = dp[i - 1][j - 1 - k];
                    b = psum[j + 1] - psum[j - k];
                    dp[i][j] = min(dp[i][j], max(a, b));
                }
            }
        }
        
        return dp[m][n - 1];
    }
};
