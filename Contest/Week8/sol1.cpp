class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string res;
        int carry = 0;
        int i;
        for (i = 0; i < num1.size() && i < num2.size(); i++) {
            int temp = num1[i] - '0' + num2[i] - '0' + carry;
            if (temp >= 10) {
                temp -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            res.push_back(temp + '0');
        }
        
        while (i < num1.size()) {
            int temp = carry + num1[i] - '0';
            if (temp >= 10) {
                temp -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            res.push_back(temp + '0');
            i++;
        }
        while (i < num2.size()) {
            int temp = carry + num2[i] - '0';
            if (temp >= 10) {
                temp -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            res.push_back(temp + '0');
            i++;            
        }
        if (carry != 0) {
            res.push_back(carry + '0');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
