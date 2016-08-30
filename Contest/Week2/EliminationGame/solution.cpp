class Solution {
public:
    int lastRemaining(int n) {

        stack<bool> st;
        while (n > 1) {
            // always view as 1,2,3
            // Remove from left
            n = n / 2;
            st.push(true);
            if (n == 1) break;
            
            // Remove the right
            if (n % 2 == 0) {
                st.push(false);
            } else {
                st.push(true);
            }
            n = n / 2;
        }
        int res = 1;
        while (!st.empty()) {
            if (st.top()) {
                res = res * 2;
            } else {
                res = res * 2 - 1;
            }
            st.pop();
        }
        return res;
    }
};
