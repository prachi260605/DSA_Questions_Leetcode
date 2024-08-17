class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = grumpy.size() ;
        vector<int> psum1(n + 1) , psum2(n + 2) ;
        for(int i = 0 ; i <= n - 1 ; i++){
            psum1[i + 1] = psum1[i] ;
            if(grumpy[i] == 0){
                psum1[i + 1] += customers[i] ;
            }
            psum2[i + 1] = psum2[i] + customers[i] ;
        }
        int ans = psum1[n] ;
        for(int i = 0 ; i + minutes - 1 <= n - 1 ; i++){
            int sum = psum1[i] + (psum2[i + minutes] - psum2[i]) + psum1[n] - psum1[i + minutes] ;
            ans = max(ans , sum) ;
        }
        return ans ;
    }
};