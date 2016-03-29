// LeetCode problem
//
// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
//
// Find all strobogrammatic numbers that are of length = n.
//
// For example,
// Given n = 2, return ["11","69","88","96"].
//
// Hint:
//
// Try to use recursion and notice that it should recurse with n - 2 instead of n - 1.

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        // Notice that in n == 2 case, '0' cannot be the leading character.
        // Thus recurse in the last layer cannot incorporate "0" and "0" at the end.
        // However in the recursion, "00" can be shown in the middle.
        return helper(n, n);
    }
    
    vector<string> helper(int n, int m) {
        // m parameter is used to check whether it is the last layer.
        if (n == 0)
            return vector<string>{""};
        if (n == 1)
            return vector<string>{"0", "1", "8"};
            
        vector<string> res;
        vector<string> preRes = helper(n - 2, m);
        for (int i = 0; i < preRes.size(); i++) {
            // If it is not the last layer, we can add "0" and "0" to around.
            if (n != m) {
                res.push_back("0" + preRes[i] + "0");
            }
            
            res.push_back("1" + preRes[i] + "1");
            res.push_back("6" + preRes[i] + "9");
            res.push_back("8" + preRes[i] + "8");
            res.push_back("9" + preRes[i] + "6");
        }
        return res;
    }
};
