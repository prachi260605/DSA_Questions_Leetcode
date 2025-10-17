class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<int> &vis, int num, vector<int>& ans){
        vis[num] = 1;

        for(int j = 0; j < isConnected.size(); j++){
            if(isConnected[num][j] == 1 && !vis[j]) dfs(isConnected, vis, j, ans);
        } 
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size();

        vector<int> vis(size, 0);

        vector<int> ans;
        int count = 0;

        for(int i = 0; i<size; i++){
            if(!vis[i]){
                count++;
                dfs(isConnected, vis, i, ans);
            }
        }
        return count;
    }
};