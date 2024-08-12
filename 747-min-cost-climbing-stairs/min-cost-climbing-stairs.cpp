class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        // Create a dp array where dp[i] represents the minimum cost to reach step i
        vector<int> dp(n + 1, 0);
        
        // Base cases: cost to reach the first two steps is the cost of those steps
        dp[0] = 0;
        dp[1] = 0;
        
        // Fill the dp array
        for (int i = 2; i <= n; ++i) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        
        // The last element in dp array will give the minimum cost to reach the top
        return dp[n];
    }
};
