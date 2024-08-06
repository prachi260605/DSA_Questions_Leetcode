class Solution {
public:
    int pivotInteger(int n) {
        int c=0,res=-1;
        for(int i=1;i<=n;i++){
            int s1=0,s2=0;
            for(int j=0;j<=i;j++){
                s1+=j;
            }
            for(int j=i;j<=n;j++){
                s2+=j;
            }
            if(s1==s2){
                res=i;
            }
        }
        return res;
    }
};