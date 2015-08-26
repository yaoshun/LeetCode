// LeetCode longest substring without repeating chars.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0)
            return 0;
        unordered_set<char> st; 
        st.insert(s[0]);
        int i = 0;
        int j = 1;
        int res = 1;
        
        // Every while loop we only move i and j at most once.
        // to make sure the programming is simple enough.
        while (i < n && j < n) {
            if (st.find(s[j]) == st.end()) {
                res = max(res, j-i+1);
                st.insert(s[j]);
                j++;
            } else {
                st.erase(s[i]);
                i++;
            }
        }
        return res;
    }
};
