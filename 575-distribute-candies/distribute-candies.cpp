class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        sort(candyType.begin(), candyType.end());
        int ans = 1; 
        for(int i = 0; i < n-1; i++)
        {
            if(candyType[i] != candyType[i+1])
            {
                ans++;
            }
        }
        int check = n/2;
        if(ans > check)
        {
            ans = check;
        }
        return ans;
    }
};