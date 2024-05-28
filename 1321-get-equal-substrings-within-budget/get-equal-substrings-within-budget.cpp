class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int c=0;//counts answer
        int l=0,h=0,diff=0;// l is left pointer, h is right pointer, diff for diffrence
        for(int h=0;h<s.size();h++)
        {
            diff+=abs(s[h]-t[h]);
            while(diff>maxCost){
                diff-=abs(s[l]-t[l]);
                l++;
            }
            c=max(c,(h-l)+1);
        }
        return c;
    }
};