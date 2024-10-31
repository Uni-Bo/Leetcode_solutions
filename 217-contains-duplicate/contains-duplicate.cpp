class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>set;
        for(auto & a: nums){
            if(set.find(a)==set.end()){
                set.insert(a);
            }
            else return true;
        }
        return false;
    }
};