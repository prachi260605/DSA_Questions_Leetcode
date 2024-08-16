// C++'s % uses "Truncated" method of calculation. But we can use the
// formula to get the right value.

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        auto mods = vector<int>(k, 0);
        int  m    = 0;
        int count = 0;

        mods[0] = 1;

        for (int num: nums) {
            m = ((m + num) % k + k) % k;
            count += mods[m];
            mods[m] += 1;
        }
        return count;
    }
};