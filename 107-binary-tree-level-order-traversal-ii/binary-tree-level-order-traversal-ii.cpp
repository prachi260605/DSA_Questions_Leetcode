class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> levels;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> level;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currentNode = q.front();
                q.pop();

                if (currentNode->left) q.push(currentNode->left);
                if (currentNode->right) q.push(currentNode->right);

                level.push_back(currentNode->val);
            }

            levels.push_back(level);
        }

        reverse(levels.begin(), levels.end());
        return levels;
    }
};