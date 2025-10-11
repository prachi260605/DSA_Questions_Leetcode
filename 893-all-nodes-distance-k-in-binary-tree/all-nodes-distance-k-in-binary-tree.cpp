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
        unordered_set<TreeNode*> visited;
        visited.insert(target);
        int dist = 0;

        while(!q.empty()){
            
            int size_q = q.size();
            if(dist == k) break;

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
            dist++;
        }

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
        
    }
};