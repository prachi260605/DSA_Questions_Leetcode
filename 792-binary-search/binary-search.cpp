class Solution {
public:

    int search(vector<int>& nums, int target) {
        int s=0,e = nums.size()-1;
        return solve(nums,s,e,target);
        
    }
    int solve(vector<int> nums, int s, int e, int k){
        int mid = s+(e-s)/2;
        //base case
        if(s>e) return -1;
        if(nums[mid]==k) return mid;

        if(nums[mid]>k) return solve(nums, s, mid-1, k);
        else return solve(nums, mid+1, e, k);
    }
};