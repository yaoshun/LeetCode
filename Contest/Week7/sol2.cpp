class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for (char& c : s) {
            mp[c]++;
        }
        
        int res = 0;
        bool odd = false;
        for (auto& pair : mp) {
            res += pair.second / 2 * 2;
            if (!odd && pair.second % 2 == 1) {
                res += 1;
                odd = true;
            }
        }
        return res;
    }
};
