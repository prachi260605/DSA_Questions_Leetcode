class Solution {
public:
    void help(vector<int>&temp,vector<int>&ans,vector<bool>&ch,int*o,int k){
        if(temp.size()==ch.size()){
            *o+=1;
            if(*o==k)ans=temp;
        }
        else{
            for(int i=0;i<ch.size();i++){
                if(ch[i])continue;
                else{
                    temp.push_back(i+1);
                    ch[i]=true;
                    help(temp,ans,ch,o,k);
                    ch[i]=false;
                    temp.pop_back();
                }
            }
        }
    }
    string getPermutation(int n, int k) {
        vector<int>temp;
        vector<int>ans;
        vector<bool>ch(n,false);
        int p=0;
        help(temp,ans,ch,&p,k);
        string an;
        for(auto x:ans){
            cout<<x<<"  ";
            an+=to_string(x);
        }
        return an;
    }
};