class Solution {
public:
    void reverse(vector<char>& str, int i , int j){
        //base cae
        if(i>j) return;
        swap(str[i++], str[j--]);
        reverse(str,i,j);
    }
    void reverseString(vector<char>& s) {
        // int i =0;
        // int j = s.size() -1;
        // while(i<j){
        //     swap(s[i++],s[j--]);
        // }

        reverse(s,0, s.size()-1);
        
    }
};