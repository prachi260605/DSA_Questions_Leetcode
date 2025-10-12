class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        int count = 0;

        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();
            count++;

            if (count == k) return curr->val;

            curr = curr->right;
        }

        return -1; // shouldn't reach here if k is valid
    }
};
