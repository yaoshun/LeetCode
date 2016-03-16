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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;

        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur || !st.empty()) {
            if (cur) {
                res.push_back(cur->val);
                if (cur->right)
                    st.push(cur->right);
                cur = cur->left;
            } else {
                cur = st.top();
                st.pop();
            }
        }
        return res;
    }
};
