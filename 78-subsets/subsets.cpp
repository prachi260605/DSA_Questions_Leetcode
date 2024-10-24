class Solution {
public:

    void solve(vector<int>& nums, int ind, vector<int> output,vector<vector<int>>&ans) {
        if(ind>=nums.size()){
            ans.push_back(output);
            return;
        }
        solve(nums, ind+1, output, ans);

        int element = nums[ind];
        output.push_back(element);
        solve(nums, ind+1, output, ans);

    }

    vector<vector<int>> subsets(vector<int>& nums) {

        int ind = 0;
        vector<int> output;
        vector<vector<int>>ans;

        solve(nums, ind, output, ans);

        return ans;

        
    }
};