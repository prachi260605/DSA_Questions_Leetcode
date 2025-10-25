class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> countt(256, 0);
        for(int i = 0; i<s.size(); i++){
            countt[s[i]]++;
            countt[t[i]]--;

        }
        for(auto i: countt){
            if(i !=0) return false;
        }
        return true;
        
    }
};