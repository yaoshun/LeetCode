// LeetCode Combination sum ii

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> r;
        dfs(candidates, 0, target, r, res);
        return res;
    }

    void dfs(vector<int>& candidates, int start, int target, vector<int>& r, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(r);
            return;
        } else if (target < 0 || start >= candidates.size()) {
            return;
        } else {
            int cnt = 1;
            while (start + cnt < candidates.size() && candidates[start + cnt] == candidates[start]) {
                cnt++;
            }

            for (int i = 0; i <= cnt; i++) {
                dfs(candidates, start + cnt, target - i * candidates[start], r, res);
                r.push_back(candidates[start]);
            }

            for (int i = 0; i <= cnt; i++) {
                r.pop_back();
            }
            return;
        }
    }
};
