class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int tot = mean * (m + n); // Total sum required for both observed and missing rolls
        int sum = accumulate(rolls.begin(), rolls.end(), 0); // Sum of observed rolls
        int excess = tot - sum; // Sum required for the missing rolls
        
        if (excess < n || excess > 6 * n) return {}; // Check if excess is in valid range
        
        vector<int> ans(n, excess / n); // Initialize all elements with the base value
        int rem = excess % n; // Remaining sum that needs to be distributed
        
        for (int i = 0; i < rem; ++i) {
            ans[i]++; // Distribute the remainder
        }
        
        return ans;
    }
};
