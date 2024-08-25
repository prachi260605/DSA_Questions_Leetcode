class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        std::queue<TreeNode*> queue;
        queue.push(root);
        int level = 1;

        while (!queue.empty()) {
            int levelSize = queue.size();

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = queue.front();
                queue.pop();

                if (node->left == nullptr && node->right == nullptr) {
                    return level;
                }

                if (node->left != nullptr) {
                    queue.push(node->left);
                }

                if (node->right != nullptr) {
                    queue.push(node->right);
                }
            }

            level++;
        }

        return level;
    }
};