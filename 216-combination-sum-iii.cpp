// LeetCode Combination Sum III

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        // first question: whether it can be repeatedly used in the set.
        // the answer is no. Otherwise, [3,3,3] should be in the second set. 
        vector<int> r;
        vector<vector<int>> res;
        dfs(k, n, 1, r, res);
        return res;
    }
    
    // we can search from 1 to 9 to avoid the reverse problem. 
    void dfs(int k, int n, int start, vector<int>& r, vector<vector<int>>& res) {
        if (n == 0 && k == 0) {
            res.push_back(r);
            return;
        } else if (n < 0 || start > 9) {
            return;
        } else {
            // Case 1: Dont't use the current number.
            dfs(k, n, start + 1, r, res);

            // Case 2: Use the current number.
            r.push_back(start);
            dfs(k - 1, n - start, start + 1, r, res);
            r.pop_back();
        }
    }
};
