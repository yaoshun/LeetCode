// LeetCode problem

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if(n <= 1)
            return 0;

        // prices are >=0 integers.
        int lowest = prices[0];
        int res = 0;
        for(int i = 1; i < n; i++) {
            if (prices[i] < lowest) {
                lowest = prices[i];
            } else {
                res = max(res, prices[i] - lowest);
            }
        }
        return res;
    }
};
