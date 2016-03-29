// LeetCode Problem

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next)
            return head;
        int len = 0;
        ListNode* iter = head;
        while (iter) {
            len++;
            iter = iter->next;
        }

        ListNode* res = helper(head, len, k);
        return res;
    }

    ListNode* helper(ListNode* head, int len, int k) {
        if (len < k)
            return head;
        if (k == 1)
            return head;

        // Reverse exactly k times.
        // Using edge case to check what happened.
        ListNode* pre = NULL;
        ListNode* cur = head;
        for (int i = 0; i < k; i++) {
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        head->next = helper(cur, len - k, k);
        return pre;
    }
};

// Use iterative method to achieve constant space.
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next)
            return head;
        int len = 0;
        ListNode* iter = head;
        while (iter) {
            len++;
            iter = iter->next;
        }

        ListNode* res = helper(head, len, k);
        return res;
    }

    ListNode* helper(ListNode* head, int len, int k) {
        if (len < k)
            return head;
        if (k == 1)
            return head;

        // Reverse exactly k times.
        // Using edge case to check what happened.
        ListNode* lastTail = NULL;
        ListNode* curHead = head;
        while (len >= k) {
            ListNode* pre = NULL;
            ListNode* cur = curHead;
            for (int i = 0; i < k; i++) {
                ListNode* temp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = temp;
            }

            if (lastTail) {
                lastTail->next = pre;
            } else {
                head = pre;
            }

            lastTail = curHead;
            curHead = cur;

            len -= k;
        }
        lastTail->next = curHead;
        return head;
    }
};

