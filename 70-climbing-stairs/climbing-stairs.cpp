class Solution {
public:
    int help(int n, unordered_map<int,int>&map)
    {
        map[0]=1;
        map[1]=1;
        if(map.find(n)==map.end())
            map[n]=help(n-1,map)+help(n-2,map);
        return map[n];
    }
    int climbStairs(int n) {
        unordered_map<int,int>map;
        return help(n,map);
    }
};