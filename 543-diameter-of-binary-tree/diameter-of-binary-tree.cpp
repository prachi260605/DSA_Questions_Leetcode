/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int Dia(int &diameter, TreeNode* root ){
        if(root == NULL) return 0;

        int left= Dia(diameter, root->left);
        int right= Dia(diameter, root->right);
    
        diameter = max(diameter, left + right);
    
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {

        int dia =0;
        Dia(dia, root);
        return dia;
        
    }
};