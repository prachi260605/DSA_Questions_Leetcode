class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dst) {
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        vector<int> adj[n];
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        queue<int> q;
        q.push(src);
        vis[src]=1;
        while(!q.empty())
        {
            int tp=q.front();
            q.pop();
            for(auto it:adj[tp])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return vis[dst];
    }
};