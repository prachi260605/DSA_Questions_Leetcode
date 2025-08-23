class Solution {
public:
void reverse(int s, int e, vector<char> &str){
    if(s >= e) return ;
    swap(str[s],str[e]);
    reverse(s+1,e-1,str);
}
    void reverseString(vector<char>& s) {
        reverse(0,s.size()-1,s);
    }
};