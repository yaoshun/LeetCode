class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int curSum = 0;
        int total = 0;
        int n = A.size();
        for (int i = 0; i < n; i++) {
            curSum += i * A[i];
            total += A[i];
        }
        
        int res = curSum;
        
        for (int i = n - 1; i >= 0; i--) {
            // Rotate and check.
            curSum = curSum + total - n * A[i];
            res = max(res, curSum);
        }
        return res;
    }
};
