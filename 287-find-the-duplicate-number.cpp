// LeetCode hard problem

// Solution 1: consider the duplicate number i.
// nums array has more than "i" count of number that is smaller or equal than i.
// Then we can use binary search to solve the problem
// The algorithm complexity is O(nlogn)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Cannot modify the array thus no sorting.
        // O(1) extra space.
        // Runtime complexity less than O(n^2).
        // It can be repeated more than once, making the sum methods (substract) not working any more.
        int n = nums.size() - 1;
        int st = 1;
        int ed = n;
        while (st < ed) {
            int mid = st + (ed - st) / 2;
            int cnt = 0;
            for (auto& element : nums) {
                if (element <= mid) {
                    cnt++;
                }
            }
            if (cnt > mid) {
                ed = mid;
            } else {
                st = mid + 1;
            }
        }
        return st;
    }
};

// Solution 2: O(n)
// Fast-Slow two pointer approach.
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Loop detection method.
        // If the value of nums is ranged, we can view it as a directed graph.
        // where nums[i] represents an edge from i => nums[i]
        // As a result, the n + 1 length array represents a linked list between node 0 and n.
        // where 0 is the start point. Besides the duplicate number, other number cannot happen
        // twice, then when we traverse to a non-dup number, we will definitely traverse out.
        // And the duplicate number is the start of a loop.
        int a = 0, b = 0;
        do {
            a = nums[nums[a]];
            b = nums[b];
        } while (a != b);
        
        a = 0;
        while (a != b) {
            a = nums[a];
            b = nums[b];
        }
        return a;
    }
};
