class DisjointSet{
    vector<int> rank, parent, size;
    public:
        DisjointSet(int n){
            rank.resize(n+1, 0);
            size.resize(n+1, 1);
            parent.resize(n+1);
            for(int i = 0; i<=n; i++){
                parent[i] = i;
            }
        }

        int findParent(int node){
            if(parent[node] == node){
                return node;
            }

            return parent[node] = findParent(parent[node]);
        }

        void unionByRank(int u, int v){
            int parentU = findParent(u);
            int parentV = findParent(v);

            if(parentU == parentV) return;

            if(rank[parentU] < rank[parentV]){
                parent[parentU] = parentV;
            }
            else if (rank[parentU] > rank[parentV]){
                parent[parentV] = parentU;
            }
            else{
                parent[parentV] = parentU;
                rank[parentU]++;
            }
        }

        void unionBySize(int u, int v){
            int parentU = findParent(u);
            int parentV = findParent(v);

            if(parentU == parentV) return;

            if(size[parentU] < size[parentV]){
                parent[parentU] = parentV;
                size[parentV] += size[parentU];
                
            }
            else {
                parent[parentV] = parentU;
                size[parentU] += size[parentV];
            }
        }

};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        DisjointSet ds(V);

        for(int i = 0; i<V; i++){
            for(int j = 0; j<V; j++){
                if(isConnected[i][j] == 1){
                    if(ds.findParent(i+1) != ds.findParent(j+1)){
                        ds.unionBySize(i+1, j+1);
                    }
                }
            }
        }
        int cnt = 0;
        for(int i = 1; i<=V; i++){
            if(ds.findParent(i) == i) cnt++;
        }
        return cnt;
    }
};