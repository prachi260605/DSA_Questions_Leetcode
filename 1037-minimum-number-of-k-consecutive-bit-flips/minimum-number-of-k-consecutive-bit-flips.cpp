class Solution {
public:
    static int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> flipped(n-k+1, 0);  // Track where flips are made
        int cnt=0,  flip_x=0;
        
        for (int i = 0; i < n; i++) {
            if (i>=k) 
                flip_x-= flipped[i-k];// outside of sized k window
            if ((flip_x&1)==nums[i]) {  // Need to flip this window
                if (i+k > n) 
                    return -1;  // Not enough elements to flip
    
                flipped[i] = 1;  // Mark the flip
                flip_x++;  // flip 
                cnt++;
            }
        }
        return cnt;
    }
};





auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();