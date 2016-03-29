// LeetCode problem
//
// Given a binary search tree and a node in it, find the in-order successor of that node in the BST.
//
// Note: If the given node has no in-order successor in the tree, return null.

// Solution 1 passed but it is inorder traversal
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        bool res = false;
        while (cur || !st.empty()) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            } else {
                TreeNode* node = st.top();
                st.pop();
                // visiting the node.
                if (res) {
                    return node;
                } else if (node == p) {
                    res = true;
                }
                
                cur = node->right;
            }
        }
        if (res)
            return NULL;
    }
};

// Solution 2, use the property of BST.
// Recursive solution
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root) {
            return NULL;
        }
        if (p == NULL) {
            while (root->left) {
                root = root->left;
            }
            return root;
        }
        
        if (root->val == p->val) {
            return inorderSuccessor(root->right, NULL);
        } else if (root->val < p->val) {
            return inorderSuccessor(root->right, p);
        } else if (root->val > p->val) {
            TreeNode* temp = inorderSuccessor(root->left, p);
            if (!temp)
                return root;
            else
                return temp;
        }
    }
};

// Solution 3 iterative solution.
// Change the problem to find the smallest value that is larger than p
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root || !p)
            return NULL;
        
        TreeNode* suc = NULL;
        // Find the smallest node that has larger value than p.
        // Like binary search criteria.
        while (root) {
            if (root->val <= p->val) {
                root = root->right;
            } else {
                suc = root;
                root = root->left;
            }
        }
        return suc;
    }
};
