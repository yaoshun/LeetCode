class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.size() < k) 
            return 0;
        
        int result = s.size();
        vector<int> chars(26, 0);
        for (int i = 0; i < s.size(); i++) {
            chars[s[i] - 'a']++;
        }
        
        int i;
        for (i = 0; i < s.size(); i++) {
            if (chars[s[i] - 'a'] < k) {
                break;
            }
        }
        
        if (i == s.size()) return s.size();
        
        return max(longestSubstring(s.substr(0, i), k), longestSubstring(s.substr(i + 1), k));
    }
};
