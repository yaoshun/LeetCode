class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.size() == 0 || s.size() == 0)
            return res;

        unordered_map<string, int> mp;
        for (auto w : words) {
            mp[w]++;
        }

        int wSize = words[0].size();

        for (int start = 0; start < wSize; start++) {
            unordered_map<string, int> slidingWindow;
            // The reson why we use cnt as the counter of the slidingWindow
            // instead of slidingWindow.size() because that we don't need to
            // erase the entries in slidingWindow when their value is zero.
            int cnt = 0;
            for (int i = start; i + wSize <= s.size(); i += wSize) {
                string word = s.substr(i, wSize);
                if (mp.find(word) == mp.end()) {
                    slidingWindow.clear();
                    cnt = 0;
                } else {
                    // The slidingWindow is full case.
                    // Delete the first word.
                    if (cnt == words.size()) {
                        string removedWord = s.substr(i - cnt * wSize, wSize);
                        slidingWindow[removedWord]--;
                        cnt--;
                    }

                    slidingWindow[word]++;
                    cnt++;

                    while (mp[word] < slidingWindow[word]) {
                        string removedWord = s.substr(i - (cnt - 1) * wSize, wSize);
                        slidingWindow[removedWord]--;
                        cnt--;
                    }
                }

                if (cnt == words.size()) {
                    res.push_back(i - (cnt - 1) * wSize);
                }
            }
        }
        return res;
    }
};
