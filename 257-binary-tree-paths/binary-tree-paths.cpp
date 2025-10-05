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
    void solve(TreeNode* root, vector<string> &ans, string st) {
        if (root == nullptr) return;

        // Add current node value to the path
        if (!st.empty()) st += "->";
        st += to_string(root->val);

        // If it's a leaf, push path to answer
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(st);
            return;
        }

        // Recur for left and right subtrees
        solve(root->left, ans, st);
        solve(root->right, ans, st);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root == nullptr) return ans;
        string st ="";
        solve(root, ans, st); 
        return ans;
    }
};