class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res = 0;
        auto check = [&](int val) {
            int cnt = 0; 
            for(; left >= (1ll<<cnt); cnt++){}
            return cnt;        
        };

        while(true) {
            if(left==right) {
                res += left; return res;
            }
            int cnt = check(left);
            if(1ll<<cnt <=right) return res;
            res += 1ll<<(--cnt);
            left -= 1ll<<(cnt); right -= 1ll<<cnt;
            
        }     
    }
};