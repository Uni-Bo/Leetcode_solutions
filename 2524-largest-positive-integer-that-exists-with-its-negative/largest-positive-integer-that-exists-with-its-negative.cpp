class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int> mp; 
        int n = nums.size(),currmax = INT_MIN,ans=-1; 

        for (int i =0 ;i<n;i++){
            if (nums[i]<0){
                mp[nums[i]]++;
            }
        }

        for (int i = 0;i<n;i++){
            if (nums[i]>0){
                if (nums[i]>currmax){
                    if (mp.find(-nums[i]) != mp.end()){
                        currmax = nums[i];
                        ans = nums[i];
                    }
                }
            }
        }
            return ans;
    }

};