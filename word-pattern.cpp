// LeetCode easy problem.
// The key is to find one to one mapping.

// Solution 1: Check size first. Then check one to one mapping.
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int cnt = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ' ') {
                cnt++;
            }
        }
        if (pattern.size() != (cnt + 1)) {
            return false;
        }
        
        // Two maps to ensure one to one mapping.
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;
        
        // Two pointer approach.
        int p = 0;
        int q = 0;
        while (p < pattern.size()) {
            int temp = q;
            while (temp < str.size() && str[temp] != ' ') {
                temp++;
            }
            string sub = str.substr(q, temp - q);
            
            if (mp1.find(pattern[p]) != mp1.end() && mp1[pattern[p]] != sub) {
                return false;
            } else if (mp2.find(sub) != mp2.end() && mp2[sub] != pattern[p]) {
                return false;
            } else {
                mp1[pattern[p]] = sub;
                mp2[sub] = pattern[p];
            }
            
            p++;
            q = temp + 1;
        }
        return true;
    }
};

// Solution 2: Using the istringstream of c++ to handle the input.
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<string, char> mp1;
        unordered_map<char, string> mp2;
        istringstream in(str);
        int i = 0, n = pattern.size();
        for (string word; in >> word; i++) {
            if (i == n) {
                return false;
            } else if (mp1.find(word) != mp1.end() && mp1[word] != pattern[i]) {
                return false;
            } else if (mp2.find(pattern[i]) != mp2.end() && mp2[pattern[i]] != word) {
                return false;
            }
            mp1[word] = pattern[i];
            mp2[pattern[i]] = word;
        }
        return i == n;
    }
};
