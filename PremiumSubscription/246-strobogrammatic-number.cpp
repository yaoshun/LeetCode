// LeetCode problem
// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
//
// Write a function to determine if a number is strobogrammatic. The number is represented as a string.
//
// For example, the numbers "69", "88", and "818" are all strobogrammatic.

class Solution {
public:
    bool isStrobogrammatic(string num) {
        int n = num.size();
        if (n == 0)
            return true;
        unordered_map<char, char> mp;
        mp['8'] = '8';
        mp['9'] = '6';
        mp['6'] = '9';
        mp['1'] = '1';
        mp['0'] = '0';
        // Two pointer approach with the preset map.
        int i = 0;
        int j = n - 1;
        while (i <= j) {
            if (mp.find(num[i]) == mp.end() || mp[num[i]] != num[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};
