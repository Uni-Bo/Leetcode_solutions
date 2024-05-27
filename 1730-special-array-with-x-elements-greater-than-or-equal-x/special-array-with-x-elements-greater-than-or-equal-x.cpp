class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=n;
        for(int i=0;i<n;i++)
        {
            cout<<nums[i]<<" "<<ans<<"\n";
            if(ans<=nums[i])
            return ans;
            ans--;
            if(ans<=nums[i])
            return -1;
        }
        return -1;
    }
};