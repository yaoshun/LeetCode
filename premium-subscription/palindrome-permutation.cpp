// LeetCode problem
//
// Given a string, determine if a permutation of the string could form a palindrome.
//
// For example,
// "code" -> False, "aab" -> True, "carerac" -> True.
//
// Hint:
//
// Consider the palindromes of odd vs even length. What difference do you notice?
// Count the frequency of each character.
// If each character occurs even number of times, then it must be a palindrome. How about character which occurs odd number of times?

class Solution {
public:
    bool canPermutePalindrome(string s) {
        if (s.size() == 0)
            return true;
            
        unordered_map<char, int> mp;
        for (char& c : s) {
            mp[c]++;
        }
       
        // Can only have one odd count char. 
        bool odd = false;
        for (auto& pair : mp) {
            if (pair.second % 2 == 0) {
                // do nothing.
            } else if (odd) {
                return false;
            } else {
                odd = true;
            }
        }
        return true;
    }
};
