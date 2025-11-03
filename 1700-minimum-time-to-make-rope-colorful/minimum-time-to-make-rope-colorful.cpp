class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int totalTime = 0;
        int n = colors.size();
        
        for (int i = 1; i < n; i++) {
            if (colors[i] == colors[i - 1]) {
                totalTime += min(neededTime[i], neededTime[i - 1]);
                // Keep the larger one for future comparisons
                neededTime[i] = max(neededTime[i], neededTime[i - 1]);
            }
        }
        return totalTime;
    }
};
