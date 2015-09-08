// LeetCode problem
//
// Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.
//
// For example:
//
// Given s = "aabb", return ["abba", "baab"].
//
// Given s = "abc", return [].
//
// Hint:
//
// If a palindromic permutation exists, we just need to generate the first half of the string.
// To generate all distinct permutations of a (half of) string, use a similar approach from: Permutations II or Next Permutation.

class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        unordered_map<char, int> mp;
        string resString;
        
        for (auto& c : s) {
            mp[c]++;
        }
        
        int odd = 0;
        for (auto& pair : mp) {
            if (pair.second % 2 == 1) {
                odd++;
                if (odd == 2)
                    return res;
                // Already store the only odd char.
                resString.push_back(pair.first);
            }
        }
        
        dfs(res, resString, mp, odd);
        return res;
    }
    
    void dfs(vector<string>& res, string& resString, unordered_map<char, int>& mp, int odd) {
        bool add = true;
        for (auto& pair : mp) {
            if (pair.second > 1) {
                add = false;
                pair.second -= 2;
                resString.push_back(pair.first);
                dfs(res, resString, mp, odd);
                resString.pop_back();
                pair.second += 2;
            }
        }
        
        // Termination point, where every node is equal or less than 0.
        if (add) {
            string t = resString.substr(odd);
            reverse(t.begin(), t.end());
            res.push_back(t + resString);
        }
    }
};
