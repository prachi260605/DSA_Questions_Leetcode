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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>> ans;
       if(root == NULL) return ans;
       queue <TreeNode*> q;
       q.push(root);
       bool f = false;
       while(!q.empty()){
        int size = q.size();
        vector<int> temp;
        for(int i =0; i<size; i++){
            TreeNode* node = q.front();
            q.pop();
            temp.push_back(node->val);
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
        }
        if(f){
            reverse(temp.begin(), temp.end());
            f = false;
        }
        else{
            f = true;
        }
        ans.push_back(temp);
       }
       return ans;

    }
};