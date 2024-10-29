class Solution {
public:
    void solve(vector<int>& candidates, int target, int index, int total, vector<int>&output, vector<vector<int>>&ans){
        if(target == total){
            ans.push_back(output);
            return;
        }
        if(index >= candidates.size() || total > target){
            return;
        }
        output.push_back(candidates[index]);
        solve(candidates, target, index, total + candidates[index], output, ans);
        output.pop_back();
        solve(candidates, target, index+1, total, output, ans);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int index =0;
        int total =0;
        vector<int>output; 
        vector<vector<int>>ans;
        solve(candidates, target, index, total, output, ans);
        return ans;    
    }
};