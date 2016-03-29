// LeetCode problem
//
// Numbers can be regarded as product of its factors. For example,
//
// 8 = 2 x 2 x 2;
//   = 2 x 4.
// Write a function that takes an integer n and return all possible combinations of its factors.
//
// Note: 
// Each combination's factors must be sorted ascending, for example: The factors of 2 and 6 is [2, 6], not [6, 2].
// You may assume that n is always positive.
// Factors should be greater than 1 and less than n.
// Examples: 
// input: 1
// output: 
// []
// input: 37
// output: 
// []
// input: 12
// output:
// [
//   [2, 6],
//   [2, 2, 3],
//   [3, 4]
// ]
// input: 32
// output:
// [
//   [2, 16],
//   [2, 2, 8],
//   [2, 2, 2, 4],
//   [2, 2, 2, 2, 2],
//   [2, 4, 4],
//   [4, 8]
// ]

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> path;
        int min = 2;
        dfs(res, path, n, min);
        return res;
    }
   
    // min can also be get from the following equation.
    // min = path.empty() ? 2 : path.back();
    // Since we start from the small factors, there isn't many repeating searches.
    void dfs(vector<vector<int>>& res, vector<int>& path, int n, int min) {
        // In this case push n to the end would not generate a sorted solution.
        // Or it will repeat previous solutions.
        if (n < min) {
            return;
        }
        
        // This is a solution.
        // Check path empty to avoid [1, n] solutions.
        if (!path.empty() && n >= min) {
            path.push_back(n);
            res.push_back(path);
            path.pop_back();
        }
        
        // Find other solutions.
        for (int i = min; i * i <= n; i++) {
            if (n % i == 0) {
                path.push_back(i);
                dfs(res, path, n/i, i);
                path.pop_back();
            }
        }
    }
};
