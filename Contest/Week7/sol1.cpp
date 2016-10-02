class Solution {
    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }
public:
    bool validWordAbbreviation(string word, string abbr) {
        int cur = 0;
        int temp = 0;
        bool res = true;
        int i;
        for (i = 0; i < abbr.size(); i++) {
            if (isDigit(abbr[i])) {
                if (abbr[i] == '0') {
                    res = false;
                    break;
                }
                temp += abbr[i] - '0';
                while (i + 1 < abbr.size() && isDigit(abbr[i + 1])) {
                    temp *= 10;
                    i++;
                    temp += abbr[i] - '0';
                }
                cur += temp;
                temp = 0;
                if (cur > word.size()) {
                    res = false;
                    break;
                }
            } else {
                if (word[cur] == abbr[i]) {
                    cur++;
                } else {
                    res = false;
                    break;
                }
            }
        }
        if (res) {
            return cur == word.size() && i == abbr.size();
        } else {
            return res;
        }
    }
};
