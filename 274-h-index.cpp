// LeetCode h-index

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (n == 0)
            return 0;
        
        vector<int> cnt(n + 1, 0);
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= n) {
                cnt[n]++;
            } else {
                cnt[citations[i]]++;
            }
        }
        
        int acc = cnt[n];
        int res = n;
        while (acc < res) {
            res--;
            if (res < 0)
                return 0;
            acc += cnt[res];
        }
        return res;
    }
};
