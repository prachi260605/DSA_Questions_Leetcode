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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(!root) return ans;

        unordered_map<TreeNode*, TreeNode*> parent;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();

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
        unordered_map<TreeNode*, bool> visited;
        visited[target] = true;
        int dist = 0;

        while(!q.empty()){
            int size_q = q.size();
            if(dist == k) break;

            for(int i = 0; i<size_q; i ++){
                TreeNode* node = q.front(); 
                q.pop();

                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if(parent[node] && !visited[parent[node]]){
                    q.push(parent[node]);
                    visited[parent[node]] = true;
                }
            }
            dist++;
        }

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
        
    }
};