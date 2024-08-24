class Solution {
private:
// unordered_map<int,bool> visited; 
vector<bool> visited;
    int dfs(int i, vector<int>& nums){
        if(visited[i])
        return 0;

        visited[i]=true;
        return 1+dfs(nums[i],nums);
    }
public:
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            visited.resize(n,false);
            ans=max(ans,dfs(i,nums));
        }

        return ans;
    }
};