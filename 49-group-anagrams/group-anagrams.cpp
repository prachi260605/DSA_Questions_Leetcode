class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        for (string s : strs) {
            vector<int> count(26, 0);
            for (char c : s) count[c - 'a']++;
            
            string key;
            for (int c : count) key += "#" + to_string(c);
            
            mpp[key].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto& it : mpp) ans.push_back(it.second);
        return ans;
    }
};
