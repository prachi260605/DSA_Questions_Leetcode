class Solution {
public:
    int findMaxK(std::vector<int>& nums) {
        std::unordered_set<int> num_set(nums.begin(), nums.end());
        int largest_k = -1;

        for (int num : nums) {
            if (num_set.find(-num) != num_set.end()) {
                largest_k = std::max(largest_k, std::abs(num));
            }
        }

        return largest_k != -1 ? largest_k : -1;
    }
};