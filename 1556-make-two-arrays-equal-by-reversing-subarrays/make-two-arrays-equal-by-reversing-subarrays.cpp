class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
    //Array initialization
    unordered_map<int, int> mp;

        //store "target" array in map
        for(int i = 0; i < target.size(); i++)
        {
            mp[target[i]]++;
        }

        ////iterate "arr" array
        for(int i = 0; i<target.size(); i++)
        {   
            //check elements of arr in map
            if(mp.find(arr[i]) == mp.end())
            return false;
            else
            {
                //decrement found elements
                mp[arr[i]]--;
                //remove zero count elements 
                if (mp[arr[i]] == 0) 
                {
                    mp.erase(arr[i]);
                }
            }   
        }
        return true;
    }
};