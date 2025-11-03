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
    int makeConnected(int n, vector<vector<int>>& connections) {

        DisjointSet ds(n);
        int extraEdge = 0;

        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            if(ds.findParent(u) != ds.findParent(v)){
                ds.unionBySize(u, v);
            }
            else{
                extraEdge++;
            }
        }

        int components = 0;

        for(int i = 0; i<n; i++){
            if(ds.findParent(i) == i){
                components++;
            }
        }

        if(extraEdge >= (components-1)) return components-1;
        else return -1;
        
    }
};