class Solution {
public:
void helper(vector<int>& nums,int i, vector<vector<int>>&ans,vector<int>&temp){
    if(i==nums.size())
    {
        ans.push_back(temp);
        return;
    }
    //take
    temp.push_back(nums[i]);
    helper(nums,i+1,ans,temp);
    //dont take;
    temp.pop_back();
    helper(nums,i+1,ans,temp);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(nums,0,ans,temp);
        return ans;
    }
};