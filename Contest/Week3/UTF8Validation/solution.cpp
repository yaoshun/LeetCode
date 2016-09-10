class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int count = 0;
        for (int i = 0; i < data.size(); i++) {
            
            if (count > 0) {
                if (data[i] >= 128 && data[i] < 128 + 64) {
                    count--;
                    continue;
                } else {
                    return false;
                }
            }
            
            if (data[i] < 128) {
                continue;
            } else if (data[i] >= 0b11000000 && data[i] < 0b11100000) {
                count = 1;
            } else if (data[i] >= 0b11100000 && data[i] < 0b11110000) {
                count = 2;
            } else if (data[i] >= 0b11110000 && data[i] < 0b11111000) {
                count = 3;
            } else {
                return false;
            }
        }
        return count == 0;
    }
};
