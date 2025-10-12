class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // Base case: empty tree
        if (!root) return new TreeNode(val);
        
        TreeNode* curr = root;
        while (true) {
            if (val < curr->val) {
                if (curr->left) curr = curr->left;
                else {
                    curr->left = new TreeNode(val);
                    break;
                }
            } else {
                if (curr->right) curr = curr->right;
                else {
                    curr->right = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};
