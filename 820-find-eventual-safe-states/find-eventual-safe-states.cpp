class Solution {
public:
    bool dfs(vector<int>& vis, vector<vector<int>>& graph, int node, vector<int> &pathVis, vector<int> &check){
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;

        for(auto it : graph[node]){
            if(!vis[it]){
                if(dfs(vis, graph, it, pathVis, check)) return true;
            }
            else if(pathVis[it]){
                return true;
            }
        }
        pathVis[node] = 0;
        check[node] = 1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(), 0);
        vector<int> pathVis(graph.size(), 0);
        vector<int> check(graph.size(), 0);

        for(int i = 0; i<graph.size(); i++){
            if(!vis[i]){
                dfs(vis, graph, i, pathVis, check);
            }
        }
        vector<int> ans;

        for(int i = 0; i<graph.size(); i++){
            if(check[i]) ans.push_back(i);
        }

        return ans;
    }
};