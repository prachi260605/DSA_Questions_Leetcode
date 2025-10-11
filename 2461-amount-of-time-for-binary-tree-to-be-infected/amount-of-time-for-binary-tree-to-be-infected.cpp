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
    int amountOfTime(TreeNode* root, int start) {
        if(!root) return 0;

        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* target;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->val == start) target = node;

                if(node->left){
                    q.push(node->left);
                    parent[node->left] = node;
                }
                if(node->right){
                    q.push(node->right);
                    parent[node->right] = node;
                }
            }
        }

        q.push(target);
        unordered_set<TreeNode*> visited;
        visited.insert(target);
        int minute = 0;

        while(!q.empty()){
            
            int size_q = q.size();

            for(int i = 0; i<size_q; i ++){
                TreeNode* node = q.front(); 
                q.pop();

                if(node->left && !visited.count(node->left)){
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if(node->right && !visited.count(node->right)){
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if(parent[node] && !visited.count(parent[node])){
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }
            }
            minute++;
        }

        return minute-1;
        
    }
        
};