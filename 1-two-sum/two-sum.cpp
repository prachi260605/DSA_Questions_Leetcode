class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        bool flag = false;
        
        for(int i = 0; i<nums.size(); i++){
            int diff = target - nums[i];

            for(int j = 0; j<nums.size(); j++){
                if(nums[j] == diff && i != j){
                    ans.push_back(i);
                    ans.push_back(j);
                    flag = true;
                }
                if(flag) break;
            }
            if(flag) break;
        }
        return ans;
    }
};