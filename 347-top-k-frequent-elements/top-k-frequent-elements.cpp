class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;

        for(auto  it : nums){
            mpp[it]++;
        }

        vector<pair<int, int>> temp;
        for(auto n : mpp){
            temp.push_back({n.second, n.first});
        }

        sort(temp.rbegin(), temp.rend());
        vector<int>ans;
        for(int i = 0; i<k; i++){
            ans.push_back(temp[i].second);
        }

        return ans;
    }
};