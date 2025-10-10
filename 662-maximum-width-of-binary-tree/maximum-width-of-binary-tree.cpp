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
    int widthOfBinaryTree(TreeNode* root) {
        int width = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()){
            int size= q.size();

            int index = q.front().second;
            int first, last; 

            for(int i = 0; i <size; i++){
                int curr_id = q.front().second - index;
                TreeNode* node = q.front().first;
                q.pop();

                if(i == 0) first = curr_id;
                if(i == size -1) last = curr_id;

                if(node->left){
                    long long indexL = (2LL*curr_id)+1;
                    q.push({node->left, indexL});
                }

                if(node->right){
                    long long indexR = (2LL*curr_id)+2;
                    q.push({node->right, indexR});
                }
            }
            width = max(width, last - first + 1);
        }
        return width;  
    }
};