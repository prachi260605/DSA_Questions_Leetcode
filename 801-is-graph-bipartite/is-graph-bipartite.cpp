class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int> &vis, int node, int color){
        vis[node] = color;

        for(auto it : graph[node]){
            if(vis[it] == -1){
                if(!dfs(graph, vis, it, !color)) return false;
            }
            else if(vis[it] == color){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(), -1);

        for(int i = 0; i<graph.size(); i++){
            if(vis[i] == -1){
                if(!dfs(graph, vis, i, 0)) return false;
            }
        }
        return true;
    }
};

