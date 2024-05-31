class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        set<int>set;
        for(int i=0;i<nums.size();i++){
            if(set.find(nums[i])==set.end())
                set.insert(nums[i]);
            else
                set.erase(nums[i]);
        }
        vector<int>ans;
        for(auto it:set)
        {
            ans.push_back(it);
        }
        return ans;
    }
};