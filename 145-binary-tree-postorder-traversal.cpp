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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;

        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* visited = NULL;
        while (cur || !st.empty()) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top();
                if (!cur->right || cur->right == visited) {
                    res.push_back(cur->val);
                    visited = cur;
                    st.pop();
                    cur = NULL;
                } else {
                    cur = cur->right;
                }
            }
        }

        return res;
    }
};
