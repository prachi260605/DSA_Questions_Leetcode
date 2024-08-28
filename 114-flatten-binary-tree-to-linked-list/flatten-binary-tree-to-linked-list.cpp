/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr)
            return;

        TreeNode* current = root;
        while (current != nullptr) {

            if (current->left != nullptr) {
                TreeNode* last = current->left;
                while (last->right != nullptr) {
                    last = last->right;
                }

                last->right = current->right;
                current->right = current->left;
                current->left = nullptr;
            }
            current = current->right;
        }
    }
};