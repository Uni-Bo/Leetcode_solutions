class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char,int>map1;
        unordered_map<char,int>map2;
        int n=s.size(),sum=0;
        for(int i=0;i<n;i++)
        {
            map1[s[i]]=i;
            map2[t[i]]=i;
        }
        for(int i=0;i<n;i++)
        {
            sum+=abs(map1[s[i]]-map2[s[i]]);
        }
        return sum;
    }
};