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
    void pathFinder(TreeNode* root, TreeNode* target, vector<TreeNode*>& path, bool& found) {
        if (!root || found) return;

        path.push_back(root);

        if (root == target) {
            found = true;
            return;
        }

        pathFinder(root->left, target, path, found);
        pathFinder(root->right, target, path, found);

        if (!found) path.pop_back();
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP, pathQ;
        bool foundP = false, foundQ = false;

        pathFinder(root, p, pathP, foundP);
        pathFinder(root, q, pathQ, foundQ);

        TreeNode* common = nullptr;

        int n = min(pathP.size(), pathQ.size());
        for (int i = 0; i < n; i++) {
            if (pathP[i] == pathQ[i]) {
                common = pathP[i];
            } else {
                break;
            }
        }

        return common;
    }
};
