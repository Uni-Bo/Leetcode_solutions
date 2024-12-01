class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>map;
        for(int i=0;i<nums.size();i++){
            int comp=target-nums[i];
            if(map.find(comp)==map.end())
            {
                map[nums[i]]=i;
            }
            else{
                return{map[comp],i};
            }
        }
        return{0,0};
    }
};