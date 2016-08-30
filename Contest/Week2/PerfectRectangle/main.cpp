#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <vector>
#include <set>
#include <map>
#include <stack>
using namespace std;

class Solution {
private:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        if (a.first != b.first) {
            return a.first < b.first;
        } else if (a.second != b.second) {
            return a.second < b.second;
        }
        return true;
    }
    static bool reccmp(vector<int>& a, vector<int>& b) {
        if (a[0] != b[0]) {
            return a[0] < b[0];
        } else if (a[1] != b[1]) {
            return a[1] < b[1];
        } else if (a[2] != b[2]) {
            return a[2] < b[2];
        } else {
            return a[3] < b[3];
        }
        return true;
    }
public:
    static bool isRectangleCover(vector<vector<int>>& rectangles) {
        pair<int, int> x(rectangles[0][0], rectangles[0][1]);
        pair<int, int> y(rectangles[0][2], rectangles[0][3]);
        for (int i = 1; i < rectangles.size(); i++) {
            pair<int, int> tempx(rectangles[i][0], rectangles[i][1]);
            pair<int, int> tempy(rectangles[i][2], rectangles[i][3]);
            if (cmp(tempx, x)) {
                x = tempx;
            }
            if (cmp(y, tempy)) {
                y = tempy;
            }
        }
        
        unsigned long long area = (y.second - x.second) * (y.first - x.first);
        
        sort(rectangles.begin(), rectangles.end(), reccmp);
        
        for (int i = 0; i < rectangles.size(); i++) {
            int j = i + 1;
            if (j < rectangles.size()) {
                if(rectangles[i][0] >= rectangles[j][2] || rectangles[i][2] <= rectangles[j][0] || rectangles[i][1] >= rectangles[j][3] || rectangles[i][3] <= rectangles[j][1]) {
                } else {
                    return false;
                }
            }
            area -= (long long)(rectangles[i][2] - rectangles[i][0]) * (rectangles[i][3] - rectangles[i][1]);
        }
        
        return area == 0;
    }
};


int main() {
    vector<vector<int>> temp = {{1,1,3,3},{3,1,4,2}, {3,2,4,4}, {1,3,2,4}, {2,3,3,4}};
    temp = {{1,1,2,3},{1,3,2,4}, {3,1,4,2}, {3,2,4,4}};
    temp = {{1,1,3,3}, {3,1,4,2}, {1,3,2,4}, {3,2,4,4}};
    temp = {{1,1,3,3}, {3,1,4,2}, {1,3,2,4}, {3,2,4,4}};
    cout << Solution::isRectangleCover(temp) << endl;
    return 0;
}
