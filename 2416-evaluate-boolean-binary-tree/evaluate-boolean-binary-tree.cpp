class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if(!root->left) return root->val == 1;
        bool leftVal = evaluateTree(root->left);
        bool rightVal = evaluateTree(root->right);
        if(root->val == 2)return leftVal or rightVal;
        return leftVal and rightVal;
    }
};