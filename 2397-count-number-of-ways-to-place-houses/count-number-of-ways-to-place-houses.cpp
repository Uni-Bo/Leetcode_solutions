#define Mod 1000000007
class Solution {
public:
    int countHousePlacements(int n) {
        if (n == 1) return 4; // Base case, 2 sides with 2 options each
        
        // Initialize dp arrays
        long long dp[n+1];
        dp[0] = 1; // 1 way to place houses on 0 plots (doing nothing)
        dp[1] = 2; // 2 ways to place houses on 1 plot (either empty or 1 house)
        
        // Fill dp array
        for (int i = 2; i <= n; ++i) {
            dp[i] = (dp[i-1] + dp[i-2]) % Mod;
        }
        
        // Result is dp[n] * dp[n] (since we have 2 independent sides)
        long long result = (dp[n] * dp[n]) % Mod;
        return (int)result;
    }
};
