// LeetCode hard problem
//
// Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.
//
// Note:
// Given target value is a floating point.
// You may assume k is always valid, that is: k ≤ total nodes.
// You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
// Follow up:
// Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?
//
// Hint:
//
// Consider implement these two helper functions:
// getPredecessor(N), which returns the next smaller node to N.
// getSuccessor(N), which returns the next larger node to N.
// Try to assume that each node has a parent pointer, it makes the problem much easier.
// Without parent pointer we just need to keep track of the path from the root to the current node using a stack.
// You would need two stacks to track the path in finding predecessor and successor node separately.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        stack<int> s1;
        stack<int> s2;
        
        // Two inorder traversal stores the ordered data.
        // Since it is using stack, we can ensure that the top of the stack
        // is closest to k.
        inorder(root, target, false, s1);
        inorder(root, target, true, s2);
        
        while (k > 0) {
            k--;
            if (s1.empty()) {
                res.push_back(s2.top());
                s2.pop();
            } else if (s2.empty()) {
                res.push_back(s1.top());
                s1.pop();
            } else if (abs(s1.top() - target) < abs(s2.top() - target)) {
                res.push_back(s1.top());
                s1.pop();
            } else {
                res.push_back(s2.top());
                s2.pop();
            }
        }
        
        return res;
    }
    
    void inorder(TreeNode* root, double target, bool reverse, stack<int>& st) {
        if (!root)
            return;
        
        inorder(reverse ? root->right : root->left, target, reverse, st);
        if ((reverse && root->val <= target) || (!reverse && root->val > target))
            return;
        
        st.push(root->val);
        inorder(reverse ? root->left : root->right, target, reverse, st);
    }
};

// Solution II implemented with the hint.
// Search the target out through getSuc and getPre.
// Then we traverse with both function.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    // Sucessor stack: corresponding to the inorder traversal of the binary
    // search tree after locate the target value.
    stack<TreeNode*> parentSuc, parentPre;
    
    // flag determines whether it allows equal case to happen.
    // When we getSuc uses the BST's element value, we did not allow equal
    // case; but when we search through target, we allow the equal case.
    TreeNode* getSuc(TreeNode* p, double target, bool flag) {
        TreeNode *suc = NULL;
        
        if (!parentSuc.empty()) {
            suc = parentSuc.top();
            parentSuc.pop();
        }
        
        while (p != NULL) {
            if (flag && p->val == target) {
                if (suc != NULL)
                    parentSuc.push(suc);
                return p;
            }
            if (p->val <= target) {
                // If we traverse in the right direction.
                // we will never go back, thus don't need to store
                // it in the stack.
                p = p->right;
            } else {
                if (suc != NULL)
                    parentSuc.push(suc);
                suc = p;
                p = p->left;
            }
        }
        
        return suc;
    }
    
    // Typical inorder traversal with memorizing stack of the parents.
    // For tracking of the predessors.
    TreeNode* getPre(TreeNode* p, double target, bool flag) {
        TreeNode* pre = NULL;
        
        if (!parentPre.empty()) {
            pre = parentPre.top();
            parentPre.pop();
        }
        
        while (p != NULL) {
            if (flag && p->val == target) {
                if (pre != NULL)
                    parentPre.push(pre);
                return p;
            }
            if (p->val >= target) {
                p = p->left;
            } else {
                if (pre != NULL)
                    parentPre.push(pre);
                pre = p;
                p = p->right;
            }
        }
        
        return pre;
    }
    
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        TreeNode *suc = getSuc(root, target, true);
        TreeNode *pre = getPre(root, target, true);
        
        vector<int> res;
        while (k > 0) {
            k--;
            if (suc == NULL) {
                res.push_back(pre->val);
                pre = getPre(pre, pre->val, false);
            } else if (pre == NULL) {
                res.push_back(suc->val);
                suc = getSuc(suc, suc->val, false);
            } else if (pre == suc) {
                // target equals to one of the value.
                res.push_back(pre->val);
                pre = getPre(pre, pre->val, false);
                suc = getSuc(suc, suc->val, false);
            } else if (abs(suc->val - target) < abs(pre->val - target)) {
                res.push_back(suc->val);
                suc = getSuc(suc, suc->val, false);
            } else {
                res.push_back(pre->val);
                pre = getPre(pre, pre->val, false);
            }
        }
        return res;
    }
};
