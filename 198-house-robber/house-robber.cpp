class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        if(n==0)return 0;
        if(n==1)return nums[0];
        dp[0]=nums[0];//1st house robbed
        dp[1]=max(nums[0],nums[1]);//1 house is robbed, but i need to decide which one better
        for(int i=2;i<n;i++)
        {
            //i represents the number of houses robbed
            dp[i]=max(
                //if I dont rob this house, I could have robbed the adjecent house
                dp[i-1],
                //if I rob this house, i get the valuable, but cant have adjacent house
                dp[i-2]+nums[i]
            );
        }
        return dp[n-1];
    }
};