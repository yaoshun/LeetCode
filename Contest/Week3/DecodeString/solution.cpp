class Solution {
public:
    string decodeString(string s) {
        string curstring = "";
        stack<int> st;
        stack<string> strst;
        // previous number start. set after ].
        int prv = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[') {
                int cnt = stoi(s.substr(prv, i - prv));
                st.push(cnt);
                prv = i + 1;
                strst.push(curstring);
                curstring = "";
            } else if (s[i] == ']') {
                int cnt = st.top();
                st.pop();
                string temp = curstring;
                for (int j = 0; j < cnt - 1; j++)
                    curstring += temp;
                curstring = strst.top() + curstring;
                strst.pop();
                prv = i + 1;
            } else if (s[i] >= '0' && s[i] <= '9') {
                continue;
            } else {
                curstring += s[i];
                prv++;
            }
        }
        return curstring;
    }
};
