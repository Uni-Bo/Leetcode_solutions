class Solution {
public:
int n;
vector<int> dp;
    int solve(int ind, vector<int> &nums) {
    if (ind < 0)
        return 0;
    // what at index =0 ->mean

    if (ind == 0)
        return nums[ind];

    if(dp[ind] != -1)return dp[ind];
    int pick = solve(ind - 2,nums) + nums[ind];
    int notPick = solve(ind - 1,nums) + 0;

    return dp[ind] =max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        n =nums.size();
        dp.assign(n+1,-1);
        return solve(n-1,nums);
    }
};