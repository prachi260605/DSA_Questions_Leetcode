class Solution {
  // Helper function to recursively count valid attendance records
    int solve(int index, int n, int absCount, int lateCount, vector<vector<vector<int>>>& dp) {
        const int MOD = 1e9 + 7;  // Define the modulo constant

        // Base case: If we've reached the end of the attendance record, return 1
        if (index >= n) {
            return 1;
        }

        // If the result is already computed, return the cached value
        if (dp[index][absCount][lateCount] != -1) {
            return dp[index][absCount][lateCount];
        }

        int ans = 0;  // Initialize the answer for this state

        // Absent module: If absences are less than 1, we can add an 'A'
        if (absCount < 1) {
            ans = ((ans % MOD) + solve(index + 1, n, absCount + 1, 0, dp) % MOD) % MOD;
        }

        // Late module: If consecutive lates are less than 2, we can add an 'L'
        if (lateCount < 2) {
            ans = ((ans % MOD) + solve(index + 1, n, absCount, lateCount + 1, dp) % MOD) % MOD;
        }

        // Present module: We can always add a 'P'
        ans = ((ans % MOD) + solve(index + 1, n, absCount, 0, dp) % MOD) % MOD;

        // Store the result in the dp array and return it
        return dp[index][absCount][lateCount] = ans;
    }
public:
    int checkRecord(int n) {
        int absCount=0;
        int lateCount=0;
        int index=0;
        // Initialize a 3D dp array with dimensions [n][2][3] and all values set to -1
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

        // Call the solve function starting from index 0 with 0 absences and 0 lates
        return solve(index,n,absCount,lateCount,dp);
        
    }
};