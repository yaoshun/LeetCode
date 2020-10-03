class Solution {
private:
public:
    bool canPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> st;
        int total = 0;
        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
            total += nums[i];
            for (auto& ele : st) {
                st.insert(nums[i] + ele);
            }
        }
        if (total % 2 == 1) {
            return false;
        } else {
            return st.find(total / 2) != st.end();
        }
    }
};
