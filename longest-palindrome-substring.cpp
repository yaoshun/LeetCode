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

// Manache algorithm O(n)
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string res = "";
        if (n == 0)
            return res;
        
        // Position count. 
        n = 2 * n + 1;
        
        // lps array
        vector<int> lps(n, 0);
        lps[0] = 0;
        lps[1] = 1;
        
        int C = 1; // center position.
        int R = 2; // center right position.
        int i; // current right postion. 
        int iMirror; // current left position.
        
        bool expand;
        int diff;
        int maxLPSLength = 1;
        int maxLPSCenterPosition = 1;
        
        for (i = 2; i < n; i++) {
            iMirror = 2 * C - i;
            // Reset expand - means no expansion required
            expand = false;
            diff = R - i;
            
            // if current right position i is within centerRight
            // position R.
            if (diff > 0) {
                if (lps[iMirror] < diff) // Case 1: mirror position is included. 
                    lps[i] = lps[iMirror];
                else { // Case 2: diff is all palindrome, but we need to expand.
                    lps[i] = diff;
                    expand = true;
                }
            } else {
                // completely new position.
                lps[i] = 0;
                expand = true;
            }
            
            if (expand) {
                while ( ((i + lps[i] + 1) < n && (i - lps[i] - 1) >= 0) &&
                ( (i + lps[i] + 1) % 2 == 0 ||
                s[(i + lps[i] + 1)/2] == s[(i - lps[i] - 1)/2])) {
                    lps[i]++;
                }
            }
            
            if (lps[i] > maxLPSLength) {
                maxLPSLength = lps[i];
                maxLPSCenterPosition = i;
            }
            
            // Change the center position
            if (i + lps[i] > R) {
                C = i;
                R = i + lps[i];
            }
        }
        
        int start = (maxLPSCenterPosition - maxLPSLength)/2;
        // Tests have shown that maxLPSLength no matter at odd or even
        // position is the actual length of the original palindromic substring.
        return s.substr(start, maxLPSLength);
    }
};
