// LeetCode problem
//
// Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.
//
// You may assume each number in the sequence is unique.
//
// Follow up:
// Could you do it using only constant space complexity?

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int n = preorder.size();
        if (n < 2)
            return true;
        
        stack<int> st;
        int low = INT_MIN;
        // Perform the inorder traversal.
        // Keep tracking of a low variable which is allowed lower bound
        // for the incoming values.
        // Once we met a value bigger than the stack top, we actually move
        // to the right subtree of it. 
        // Then we update the lower bound and adjust the stack to the right position.
        for (int& p : preorder) {
            if (p < low)
                return false;
            while (!st.empty() && p > st.top()) {
                low = st.top();
                st.pop();
            }
            st.push(p);
        }

        return true;
    }
};

// Solution with O(1) extra space.
// Using the first few values of the array as the stack.
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int n = preorder.size();
        if (n < 2)
            return true;

        // Using the first few values of the given array
        // as the stack. Since we don't need it any more.
        int low = INT_MIN;
        int i = -1;
        for (int& p : preorder) {
            if (p < low)
                return false;
            while (i >= 0 && p > preorder[i]) {
                low = preorder[i];
                i--;
            }
            i++;
            preorder[i] = p;
        }

        return true;
    }
};
