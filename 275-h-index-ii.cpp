// LeetCode

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (n == 0)
            return 0;
        int st = 0;
        int ed = n - 1;
        // Find the mininum number that 
        // citations[i] >= n - i;
        while (st < ed) {
            int mid = st + (ed - st) / 2;
            if (citations[mid] >= n - mid) {
                ed = mid;
            } else {
                st = mid + 1;
            }
        }
        
        // Prevent the case that no number satisfy
        // citations[i] >= n - i;
        // For instance, citations[n - 1] < n - (n - 1) = 1;
        return citations[st] >= n - st ? (n - st) : 0;
    }
};
