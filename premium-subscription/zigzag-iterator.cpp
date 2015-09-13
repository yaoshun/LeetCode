// LeetCode problem
//
// Given two 1d vectors, implement an iterator to return their elements alternately.
//
// For example, given two 1d vectors:
//
// v1 = [1, 2]
// v2 = [3, 4, 5, 6]
// By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].
//
// Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?

// The key for this type of problem is that hasNext is called first before
// calling next repeatedly.
// Solution for 2 vector cases.
class ZigzagIterator {
private:
    // indicate which vector it is in right now.
    // [row][col] definitely there is a number.
    int pos;
    vector<int> v;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        pos = 0;
        int l1 = 0, l2 = 0;
        while (l1 < v1.size() && l2 < v2.size()) {
            v.push_back(v1[l1]);
            l1++;
            v.push_back(v2[l2]);
            l2++;
        }
        while (l1 < v1.size()) {
            v.push_back(v1[l1]);
            l1++;
        }
        while (l2 < v2.size()) {
            v.push_back(v2[l2]);
            l2++;
        }
    }

    int next() {
        pos++;
        return v[pos - 1];
    }

    bool hasNext() {
        return pos != v.size();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */

class ZigzagIterator {
private:
    int pos;
    vector<int> v;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        // Initialize pos to zero
        pos = 0;
        
        // solution for k 1d vectors.
        vector<vector<int>> kv;
        kv.push_back(v1);
        kv.push_back(v2);

        // Traverse through vector<vector<int>> and output the result to v.
        int maxCol = 0;
        for (auto& arr : kv) {
            maxCol = max(maxCol, static_cast<int>(arr.size()));
        }
        
        for (int i = 0; i < maxCol; i++) {
            for (int j = 0; j < kv.size(); j++) {
                if (i < kv[j].size())
                    v.push_back(kv[j][i]);
            }
        }
    }

    int next() {
        pos++;
        return v[pos - 1];
    }

    bool hasNext() {
        return pos != v.size();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */

// Solution without additional space.
// Be familiar with the iterators in c++;
class ZigzagIterator {
private:
    int pos;
    vector<vector<int>::iterator> viter;
    vector<vector<int>::iterator> vend;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        viter.push_back(v1.begin());
        viter.push_back(v2.begin());
        vend.push_back(v1.end());
        vend.push_back(v2.end());
        pos = 0;
    }

    int next() {
        int res = *(viter[pos]);
        viter[pos]++;
        pos++;
        if (pos == vend.size())
            pos = 0;
        return res;
    }

    bool hasNext() {
        int count = 0;
        while (viter[pos] == vend[pos]) {
            pos++;
            count++;
            
            if (pos == vend.size()) {
                pos = 0;
            }
            
            if (count == vend.size()) {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
