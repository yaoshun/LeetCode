// LeetCode longest palindromic substring.

class Solution {
public:
    string longestPalindrome(string s) {
        // Write your code here
        int n = s.size();
        if (n == 0)
            return 0;
        // At least it is 1.
        int maxLen = 0;
        string res;
        for (int i = 0; i < n; i++) {
            // Each char there are two possibilities of
            // palindrome.
            // Case one: use s[i] as the center.
            int len = 1;
            int st = i - 1;
            int ed = i + 1;
            while (ed < n && st >= 0 && s[st] == s[ed]) {
                st--;
                ed++;
                len += 2;
            }
            if (len > maxLen) {
                maxLen = len;
                res = s.substr(st + 1, ed - st - 1);
            }

            // Case two: use s[i+0.5] as the center.
            len = 0;
            st = i;
            ed = i + 1;
            while (ed < n && st >= 0 && s[st] == s[ed]) {
                st--;
                ed++;
                len += 2;
            }

            if (len > maxLen) {
                maxLen = len;
                res = s.substr(st + 1, ed - st - 1);
            }
        }
        return res;
    }
};
