class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> sets;
        unordered_map<char, int> sett;
        for (char& c : s) {
            sets[c]++;
        }
        for (char& c : t) {
            sett[c]++;
        }
        
        for (auto pair : sett) {
            if (sets.find(pair.first) == sets.end() ||
            sets[pair.first] != pair.second) {
                return pair.first;
            }
        }
        return t[0];
    }
};
