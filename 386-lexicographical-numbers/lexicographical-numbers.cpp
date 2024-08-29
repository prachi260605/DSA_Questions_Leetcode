class Solution {
public:
struct Node{
    Node* links[10];
    bool flag=false;
    bool containsKey(char ch){
        return links[ch-'0']!=NULL;
    }
    void put(char ch, Node* node){
        links[ch-'0'] = node;
    }
    Node* get(char ch){
        return links[ch-'0'];
    }
    void setEnd(){
        flag = true;
    }
    bool getEnd(){
        return flag;
    }
};
class Trie{
public:
    Node* root;

    Trie(){
        root = new Node();
    }
    void insert(string& num){
        Node* temp = root;
        for(int i=0; i<num.size(); i++){
            if(!temp->containsKey(num[i])){
                temp->put(num[i], new Node());
            }
            temp = temp->get(num[i]);
        }
        temp->setEnd();
    }
};

    void dfs(Node* root, int curr, vector<int>& ans){
        if(root==NULL){
            return;
        }
        if(root->getEnd()==true){
            ans.push_back(curr);
        }
        for(char ch='0'; ch<='9'; ch++){
            if(root->containsKey(ch)){
                dfs(root->get(ch), (curr*10)+(ch-'0'), ans);
            }
        }
    }

    vector<int> lexicalOrder(int n) {
        Trie trie;
        for(int i=1; i<=n; i++){
            string s = to_string(i);
            trie.insert(s);
        }

        vector<int> ans;
        dfs(trie.root,0,ans);
        return ans;
    }
};