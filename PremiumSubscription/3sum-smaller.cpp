// LeetCode medium
//
// Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.
//
// For example, given nums = [-2, 0, 1, 3], and target = 2.
//
// Return 2. Because there are two triplets which sums are less than 2:
//
// [-2, 0, 1]
// [-2, 0, 3]
// Follow up:
// Could you solve it in O(n2) runtime?

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        // Typical two pointer approach.
        int n = nums.size();
        if (n < 3)
            return 0;
        sort(nums.begin(), nums.end());
        
        int res = 0;
        for (int i = 0; i < n - 2; i++) {
            int sum = target - nums[i];
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                if (nums[j] + nums[k] < sum) {
                    // i, j, (j+1 to k) is all the solutions.
                    res += k - j;
                    j++;
                } else {
                    k--;
                }
            }
        }
        return res;
    }
};
