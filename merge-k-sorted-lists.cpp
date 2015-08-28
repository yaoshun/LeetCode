/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Divide and Conquer approach.
        // The complexity of merging two lists is O(m+n)
        // Thus theoratically we should merge smaller ones
        // First to avoid unnecessarily processing large ones
        // continuously.
        int n = lists.size();
        if (n == 0)
            return NULL;
        while (n > 1) {
            int mid = (n + 1) / 2; 
            // we merge list i and list (i+mid) repeatively.
            for (int i = 0; i < n / 2; i++) {
                lists[i] = mergeTwo(lists[i], lists[i + mid]);
            }
            n = mid;
        }
        return lists[0];
    }

    ListNode* mergeTwo(ListNode* a, ListNode* b) {
        // This is implemented using a recursive way.
        // We can also use iterative while loop to achieve
        // the same effect.
        if (!a)
            return b;
        if (!b)
            return a;
        // At this point, both are not NULL.
        if (a->val < b->val) {
            a->next = mergeTwo(a->next, b);
            return a;
        } else {
            b->next = mergeTwo(b->next, a);
            return b;
        }
    }
};

// The second solution is trying to use the Heap data structure
// to solve the problem.
class Solution {
public:
    struct compNode {
        bool operator()(ListNode *p, ListNode *q) const {
            return p->val > q->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*> &lists) {
        // By default, priority queue is max queue.
        // Thus we use p->val > q->val to determine that p is smaller.
        // Then the minimum value will be put at the top of the heap.
        priority_queue<ListNode*, vector<ListNode*>, compNode> pq;
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i])
                pq.push(lists[i]);
        }

        while (!pq.empty()) {
            tail->next = pq.top();
            tail = tail->next;
            pq.pop();
            if (tail->next)
                pq.push(tail->next);
        }

        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
