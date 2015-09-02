// LeetCode Combination Sum

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // DFS and backtracking to solve the problem.
        // The key constraints is that everything and the results are positive.
        vector<vector<int>> res;
        vector<int> r;
        
        if (candidates.size() == 0)
            return res;
        
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target, r, res);
        return res;
    }
    
    void dfs(vector<int>& candidates, int start, int target, vector<int>& r, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(r);
            return;
        } else if (start > candidates.size() - 1) {
            return;
        } else {
            for (int i = 0; i * candidates[start] <= target; i++) {
                dfs(candidates, start + 1, target - i * candidates[start], r, res);
                r.push_back(candidates[start]);
            }
            while (r.back() == candidates[start])
                r.pop_back();
            return;
        }
    }
};
