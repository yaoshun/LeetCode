// Leetcode add two numbers solution.

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // If the list is stored reversely to form a number, 
        // we should use the  
        ListNode* dummyHead = new ListNode(0);
        ListNode* p=l1;
        ListNode* q=l2;
        ListNode* cur = dummyHead;
        int carry=0;

        while (p || q) {
            int x = p ? p->val : 0;
            int y = q ? q->val : 0;
            int digit = x + y + carry;
            carry = digit/10;
            cur->next = new ListNode(digit%10);
            cur = cur->next;
            if(p) p = p->next;
            if(q) q = q->next;
        }

        // In this case, we need to add one more node.
        if(carry) {
            cur->next = new ListNode(1);
        }

        // Necessary step to clear the dummy node.
        ListNode* res = dummyHead->next;
        delete dummyHead;
        return res;
    }
};
