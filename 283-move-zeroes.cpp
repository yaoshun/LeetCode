// LeetCode easy problem

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = 0;
        while (j < nums.size()) {
            if (nums[j] == 0) {
                j++;
            } else {
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
        }
        return;
    }
};

// minimize operations by finishing the swapping at the end.
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = 0;
        for (; j < nums.size(); j++) {
            if (nums[j] != 0) {
                nums[i] = nums[j];
                i++;
            }
        }
        for (; i < nums.size(); i++) {
            nums[i] = 0;
        }
        return;
    }
};
