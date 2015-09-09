// LeetCode problem
//
// Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.
//
// Note:
// Given target value is a floating point.
// You are guaranteed to have only one unique value in the BST that is closest to the target.

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
    int closestValue(TreeNode* root, double target) {
        if (!root)
            return -1;
        if (target == root->val) {
            return root->val;
        } else if (target < root->val) {
            if (root->left) {
                int temp = closestValue(root->left, target);
                return abs(temp - target) < abs(target - root->val) ?
                temp : root->val;
            } else {
                return root->val;
            }
        } else {
            if (root->right) {
                int temp = closestValue(root->right, target);
                return abs(temp - target) < abs(target - root->val) ?
                temp : root->val;
            } else {
                return root->val;
            }
        }
    }
};

// Simplified recursive version.
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
    int closestValue(TreeNode* root, double target) {
        // root must exists to make the problem meaningful.
        int a = root->val;
        if (a == target)
            return a;
        TreeNode* kid = target < a ? root->left : root->right;
        if (!kid)
            return a;
            
        int b = closestValue(kid, target);
        return abs(a - target) < abs(b - target) ? a : b;
    }
};

// Iterative version.
// Use the "target < root->val ? root->left : root->right" to determine the path
// and traverse through it.
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
    int closestValue(TreeNode* root, double target) {
        // root must exists to make the problem meaningful.
        int closest = root->val;
        while (root) {
            if (abs(closest - target) > abs(root->val - target)) {
                closest = root->val;
            }
            root = target < root->val ? root->left : root->right;
        }
        return closest;
    }
};
