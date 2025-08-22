class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return 0;
        long result = 0;
        int num =x;
        while(x){
            int digit = x%10;
            result = (result*10) + digit;
            x = x/10;
        }
        if(result == num) return true;
        else return false;
        
    }
};