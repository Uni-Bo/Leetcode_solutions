class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int>set;
        for(auto n:nums){
            if(set.find(n)!=set.end()) return n;
            set.insert(n);
        }
    return 0;
    }
};