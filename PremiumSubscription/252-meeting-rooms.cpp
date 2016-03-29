// LeetCode
//
// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.
//
// For example,
// Given [[0, 30],[5, 10],[15, 20]],
// return false.
//

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
    static bool cmp(const Interval& a, const Interval& b) {
        if (a.start != b.start) {
            return a.start < b.start;
        } else {
            return a.end < b.end;
        }
    }
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        // The problem is to determine this intervals did not
        // overlap with each other.
        sort(intervals.begin(), intervals.end(), cmp);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start < intervals[i - 1].end) {
                return false;
            }
        }
        return true;
    }
};
