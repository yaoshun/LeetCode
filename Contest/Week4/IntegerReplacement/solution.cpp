class Solution {
private:
    int helper(long long n) {
        if (n == 1) {
            return 0;
        } else if (n & 1) {
            return min(helper(n + 1), helper(n - 1)) + 1;
        } else {
            return helper(n/2) + 1;
        }   
    }
public:
    int integerReplacement(int n) {
        return helper((long long)n);
    }
};
