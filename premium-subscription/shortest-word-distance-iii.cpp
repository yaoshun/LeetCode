// LeetCode Premium subscription problem
// This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.
//
// Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
//
// word1 and word2 may be the same and they represent two individual words in the list.
//
// For example,
// Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
//
// Given word1 = “makes”, word2 = “coding”, return 1.
// Given word1 = "makes", word2 = "makes", return 3.
//
// Note:
// You may assume word1 and word2 are both in the list.

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        // In two word case, pos1 and pos2 store the latest index of word1 and word2.
        // In one word case, pos1 stores the second latest index, pos2 stores the latest.
        int pos1 = -1;
        int pos2 = -1;
        int res = INT_MAX;
        
        for (int i = 0; i < words.size(); i++) {
            if (word1 == words[i]) {
                pos1 = i;
            }
            
            // Cannot use else if in this case.
            if (word2 == words[i]) {
                if (word1 == word2) {
                    pos1 = pos2;
                }
                pos2 = i;
            }
            
            if (pos1 >= 0 && pos2 >= 0) {
                res = min(res, abs(pos1 - pos2));
            }
        }
        return res;
    }
};
