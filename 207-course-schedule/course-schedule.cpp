class Solution {
public:
    int n;
    vector<vector<int>> adj;
    unordered_map<int,bool> m;
    bool dfs(int x)
    {
        if(m.find(x)!=m.end())
         return m[x];
        m[x]=false;
        for(auto& c:adj[x])
        {
            if(!dfs(c))
             return m[x]=false;
        }
        return m[x]=true;
    }
    bool canFinish(int n, vector<vector<int>>& a) {
        
        this->n=n;
        this->adj.resize(n);
        for(int i=0;i<a.size();i++)
        {
            adj[a[i][0]].push_back(a[i][1]);
        }
        bool ans=true;
        for(int i=0;i<n;i++)
        {
           if(m.find(i)==m.end())
            dfs(i);
          ans=ans && m[i];
             
        }

        return ans;

    }
};