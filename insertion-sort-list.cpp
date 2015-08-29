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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* cur = head->next;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        head->next = NULL;

        while (cur) {
            // Store the variable for next cycle.
            // Currently need to insert "ins" node.
            ListNode* ins = cur;
            cur = cur->next;

            ListNode* iter = dummy;
            while (iter->next && ins->val > iter->next->val) {
                iter = iter->next;
            }

            // No matter iter->next is NULL or not, we should
            // do the same thing.
            ListNode* temp = iter->next;
            iter->next = ins;
            ins->next = temp;
        }
        ListNode* res = dummy->next;
        delete dummy;
        return res; 
    }
};
