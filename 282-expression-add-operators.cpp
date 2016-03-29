// LeetCode Hard problem

class Solution {
private:
    // cur: expression generated so far
    // pos: current visiting position of num
    // cv: cumulative value so far.
    // pv: previous operand value (if multiple * is involved, keep track of the multiplication of them).
    // op: previous operator used.
    void dfs(vector<string>& res, const string& num, const int target, string cur, int pos, const long cv, const long pv, const char op) {
        if (pos == num.size() && cv == target) {
            res.push_back(cur);
        } else {
            for (int i = pos + 1; i <= num.size(); i++) {
                string t = num.substr(pos, i - pos);
                long now = stol(t);
                if (to_string(now).size() != t.size())
                    continue;
                dfs(res, num, target, cur + '+' + t, i, cv + now, now, '+');
                dfs(res, num, target, cur + '-' + t, i, cv - now, now, '-');
                // Three cases in multiplication sign. The op is the previous op before 
                // multiple '*'s. 
                if (op == '-') {
                    dfs(res, num, target, cur + '*' + t, i, cv + pv - pv * now, pv * now, op);
                } else if (op == '+') {
                    dfs(res, num, target, cur + '*' + t, i, cv - pv + pv * now, pv * now, op);
                } else if (op == '#') {
                    dfs(res, num, target, cur + '*' + t, i, pv * now, pv * now, op);
                }
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        if (num.empty())
            return res;
        
        // At least use one number to avoid empty set generate 0 case.
        for (int i = 1; i <= num.size(); i++) {
            string s = num.substr(0, i);
            long cur = stol(s);
            // Avoid trailing zeros.
            if (to_string(cur).size() != s.size()) {
                continue;
            }
            dfs(res, num, target, s, i, cur, cur, '#');
        }
        
        return res;
    }
};
