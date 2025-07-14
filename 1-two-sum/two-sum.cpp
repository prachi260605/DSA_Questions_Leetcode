class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int t = 0;
        for(int i =0; i<nums.size(); i++){
            t = target -nums[i];
            auto it = find(nums.begin() +i+1, nums.end(), t);
            if(it != nums.end()){
                int d = it-nums.begin();
                return {i, d};
            } 
        }
        return {};
        
        
    }
};