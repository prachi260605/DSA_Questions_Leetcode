class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int c1 = 0, c0 = 0;
        // Map to store the first occurrence of each count difference
        // initialized with 0 difference at -1 index
        unordered_map<int, int> countMap{{0, -1}}; 
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) c0++;
            else c1++;
            int diff = c0 - c1;
            if (countMap.find(diff) != countMap.end()) {
                // If this difference is already encountered
                // then current position - position of the first occurrence of the same difference
                ans = max(ans, i - countMap[diff]);
            } else {
                // If this difference is encountered first time
                countMap[diff] = i;
            }
        }
        return ans;
    }
};