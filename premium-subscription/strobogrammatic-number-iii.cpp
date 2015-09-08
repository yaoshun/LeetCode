// LeetCode hard problem
//
// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
//
// Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.
//
// For example,
// Given low = "50", high = "100", return 3. Because 69, 88, and 96 are three strobogrammatic numbers.
//
// Note:
// Because the range might be a large number, the low and high numbers are represented as string.

class Solution {
private:
    // For consistently use to generate the strobogrammatic number.
    unordered_map<char, char> mp = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
   
    // The key here is that equal returns true.
    // Thus low<= <=high can be translated to compare(low, str) && compare(str, high). 
    static bool compare(const string& a, const string& b) {
        if (a.size() != b.size())
            return a.size() < b.size();
        int i = 0;
        while (i < a.size() && a[i] == b[i]) {
            i++;
        }
        // Notice that in the equal case it will return smaller.
        return i == a.size() || a[i] < b[i];
    }
    
public:
    int strobogrammaticInRange(string low, string high) {
        // If two strings are of the same length, we can compare the size
        // of the string in the lexicographic order.
        int res = 0;
        for (int i = low.size(); i <= high.size(); i++) {
            string temp(i, ' ');
            strobogrammaticCount(temp, res, low, high, 0, i - 1);
        }
        return res;
    }
    
    // Count the number of a specific length.
    // lo and hi is used for recursion to generate the strobogrammatic numbers.
    // The generated string is stored in temp for comparison with low and high.
    void strobogrammaticCount(string temp, int& res, string& low, string& high, int lo, int hi) {
        if (lo > hi) {
            //
            if ((temp[0] != '0' || temp.size() == 1) && compare(low, temp) && compare(temp, high))
                res++;
            return;
        }
        
        // Recursively generate all the strobogrammatic number in a specific size.
        for (auto m : mp) {
            temp[lo] = m.first;
            temp[hi] = m.second;
            if ((lo == hi && m.first == m.second) || lo < hi)
                strobogrammaticCount(temp, res, low, high, lo + 1, hi - 1);
        }
    }
};
