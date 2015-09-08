// LeetCode easy problem
//
// Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:
//
// "abc" -> "bcd" -> ... -> "xyz"
// Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.
//
// For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
// Return:
//
// [
//   ["abc","bcd","xyz"],
//   ["az","ba"],
//   ["acef"],
//   ["a","z"]
// ]
// Note: For the return value, each inner list's elements must follow the lexicographic order.

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        // Hashset key is the initial string of the group.
        // Thus we need a function to process every string to shift to the initial state.
        unordered_map<string, vector<string>> mp;
        for (auto& s : strings) {
            mp[convert(s)].push_back(s);
        }
        
        vector<vector<string>> res;
        for (auto m : mp) {
            res.push_back(m.second);
            sort(res.back().begin(), res.back().end());
        }
        return res;
    }
    
    // Now we realized that the rotated string is also fine.
    // for example, "az" and "yx" belongs to the same group.
    // We change the convert function to ensure that the first char is 'a'.
    string convert(string s) {
        if (s.empty())
            return "";
        
        string res(s.size(), ' ');
        for (int i = 0; i < s.size(); i++) {
            if (s[i] - s[0] < 0) {
                res[i] = s[i] - s[0] + 26 + 'a';
            } else {
                res[i] = s[i] - s[0] + 'a';
            }
        }
        return res;
    }
};
