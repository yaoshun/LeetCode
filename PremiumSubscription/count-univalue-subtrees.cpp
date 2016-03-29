// LeetCode medium problem
// Given a binary tree, count the number of uni-value subtrees.
//
// A Uni-value subtree means all nodes of the subtree have the same value.
// 
// For example:
// Given binary tree,
//               5
//              / \
//             1   5
//            / \   \
//           5   5   5
// return 4.

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
    int countUnivalSubtrees(TreeNode* root) {
        if (!root)
            return 0;
        int res = 0;
        isUnivalTree(root, res);
        return res;
    }
    
    // Make sure the input to root is not empty.
    // Initially I'm using a very long && operator, which causes that if the leftside is
    // false, it would not evaluate isUnivalTree(root->right) and get the right results.
    bool isUnivalTree(TreeNode* root, int& res) {
        bool left, right;
        if (root->left) {
            left = isUnivalTree(root->left, res) && root->val == root->left->val;
        } else {
            left = true;
        }
        
        if (root->right) {
            right = isUnivalTree(root->right, res) && root->val == root->right->val;
        } else {
            right = true;
        }
        
        if (left && right) {
            res++;
            return true;
        } else
            return false;
    }
};
