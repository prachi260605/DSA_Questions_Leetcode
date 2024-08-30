class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Map to keep track of words in the wordList and their visit status
        map<string,int> m;
        int n = wordList.size();
        for(int i = 0; i < n; i++){
            m[wordList[i]]++;  // Increment count for each word (used as a flag for whether it has been visited)
        } 

        // Initialize the starting point
        int ans = 1;  // Represents the level or the number of transformations
        queue<string> q;
        q.push(beginWord);
        m[beginWord] = 0;  // Mark the beginWord as visited

        // Vector to store the next level of words to explore
        vector<string> v;

        // Perform BFS
        while(!q.empty()){
            string s = q.front();
            string s1 = s;  // Copy of the current word to restore after modification
            q.pop();

            // Try changing each character of the current word
            for(int i = 0; i < s.length(); i++){
                for(char j = 'a'; j <= 'z'; j++){
                    s[i] = j;  // Modify the ith character

                    // If the modified word is valid (exists in the wordList and not yet visited)
                    if(s != s1 && m[s] > 0){
                        if(s == endWord) return ans + 1;  // If we reach the endWord, return the result
                        m[s] = 0;  // Mark this word as visited
                        v.push_back(s);  // Add it to the next level of BFS exploration
                    }
                }
                s[i] = s1[i];  // Restore the original character before moving to the next position
            }

            // If the current level is fully explored and the queue is empty,
            // push all words from the next level into the queue
            if(q.empty() && v.size() > 0){
                for(int i = 0; i < v.size(); i++){
                    q.push(v[i]);  // Add the next level words to the queue
                }
                ans++;  // Increment the transformation count
                v.clear();  // Clear the vector for the next level
            }
        }

        // If no transformation sequence is found
        return 0;
    }
};