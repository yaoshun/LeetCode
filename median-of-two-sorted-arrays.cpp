// LeetCode Median of two sorted arrays.

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        if (total % 2 != 0) {
            return findKth(nums1, 0, m - 1, nums2, 0, n - 1, (total+1)>>1);
        } else {
            return (findKth(nums1, 0, m - 1, nums2, 0, n - 1, total>>1) +
            findKth(nums1, 0, m - 1, nums2, 0, n - 1, (total>>1)+1))/2;
        }
    }
    
    double findKth(vector<int>& nums1, int i, int j, vector<int>& nums2, int m, int n, int k) {
        // Keep the smaller size array at the beginning.
        if (n - m < j - i)
            return findKth(nums2, m, n, nums1, i, j, k);
        if (i > j)
            return nums2[m + k - 1];
        
        if (k == 1)
            return min(nums1[i], nums2[m]);

        // Check k == 1 in order to make sure that pa >= 1
        // and pb >= 1 in which case the index will make sense. 
        int pa = min(k/2, j - i + 1);
        int pb = k - pa;
        
        if (nums1[i + pa -1] <= nums2[m + pb - 1]) {
            return findKth(nums1, i + pa, j, nums2, m, n, k - pa);
        } else {
            return findKth(nums1, i, j, nums2, m + pb, n, k - pb);
        }
    }
};
