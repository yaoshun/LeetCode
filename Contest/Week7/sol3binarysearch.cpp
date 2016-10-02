typedef long long ll;
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<ll> psum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            psum[i + 1] = psum[i] + nums[i];
        }
        ll st = psum[n] / m;
        
        ll ed = psum[n];
        while (st < ed) {
            ll mid = st + (ed - st) / 2;
            int seg = 0;
            ll cursum = 0;
            int cur = 0;
            bool res = true;
            for (int i = 0; i < n; i++) {
                if (nums[i] > mid) {
                    res = false;
                    break;
                }
                cursum += nums[i];
                if (cursum > mid) {
                    i--;
                    seg++;
                    cursum = 0;
                    cur = i + 1;
                }
            }
            if (cur < n) {
                seg++;
            }
            
            if (!res || seg > m) {
                st = mid + 1;
            } else {
                ed = mid;
            }
        }
        
        return (int)st;
    }
};
