class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();

        // Create a set of words from the vector so that the lookup cost in the
        // set becomes O(1)
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        // Initialize the lookup table
        vector<bool> dp(n + 1, false);

        // Set the first element to true as it represents the empty string
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                // Checking if the substring from j to i is present in the
                // wordSet and dp[j] is true
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    // If a substring is found, no need to check further smaller
                    // substrings
                    break;
                }
            }
        }

        // Return the last element of dp array
        return dp[n];
    }
};