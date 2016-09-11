typedef pair<int, int> pp;
bool cmp(const pp& x, const pp& y) { return x.first < y.first; }

class Solution {
private:
    vector<pp> arr;
public:
    Solution(vector<int> nums) {
        for (int i = 0; i < nums.size(); i++) {
            arr.push_back(pp{nums[i], i});
        }
        sort(arr.begin(), arr.end(), cmp);
    }
    
    int pick(int target) {
        auto bounds = equal_range(arr.begin(), arr.end(), pp{target, 0}, cmp);
        int s = bounds.first - arr.begin();
        int e = bounds.second - arr.begin();
        int r = e - s;
        return arr[s + (rand() % r)].second;
    }
};
