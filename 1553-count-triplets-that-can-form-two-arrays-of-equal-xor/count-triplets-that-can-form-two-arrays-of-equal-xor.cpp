class Solution {
public:
    static int countTriplets(vector<int>& arr) {
        int n=arr.size();
        if (n==1) return 0;
        // a=arr[i] ^ arr[i+1] ^ ... ^ arr[j-1]
        // b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
        // Note i < j <= k 
        // a==b <=> a^b==0  
        // For given i, k there are (k-i) choices for  j
        vector<int> xor_sum(n, arr[n-1]);// xor_sum[i]=xor(arr[i:]) from index i on
        int ans=0;
        for(int i=n-2; i>=0; i--){
            xor_sum[i]=xor_sum[i+1]^arr[i];
            if (xor_sum[i]==0)
                ans+=(n-1-i);//i<j<=k=n-1
        }
         
        for(int i=0; i<n-1; i++){  
            for(int k0=n-1; k0>i+1; k0--){
                xor_sum[i]^=arr[k0];//xor_sum ends at k=k0-1
                if (xor_sum[i]==0) ans+=(k0-1-i);
            }

        }
       
        return ans;
    }
};