// LeetCode problem
//
// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.
//
// For example,
// Given [[0, 30],[5, 10],[15, 20]],
// return 2.

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
private:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        if (a.first != b.first) {
            return a.first < b.first;
        } else {
            return a.second < b.second;
        }
    }
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        // Dissemble the intervals into individual time points.
        // At a specific time point, consider the endings first.
        // Thus set end into -1.
        vector<pair<int, int>> t;
        for (auto& i : intervals) {
            t.push_back({i.start, 1});
            t.push_back({i.end, -1});
        }
        
        sort(t.begin(), t.end(), cmp);
        
        int cur = 0;
        int res = 0;
        for (int i = 0; i < t.size(); i++) {
            if (t[i].second == 1)
                cur++;
            else
                cur--;
            res = max(res, cur);
        }
        return res;
    }
};
