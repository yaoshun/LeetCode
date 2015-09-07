// LeetCode binary search problem

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (n == 0)
            return -1;
        int st = 1;
        int ed = n;
        while (st < ed) {
            int mid = st + (ed - st) / 2;
            if (isBadVersion(mid)) {
                ed = mid;
            } else {
                st = mid + 1;
            }
        }
        return st;
    }
};
