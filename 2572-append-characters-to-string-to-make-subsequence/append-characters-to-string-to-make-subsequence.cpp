class Solution {
public:
    int appendCharacters(string s, string t) {
        int c=t.size();
        int l=0,r=0,f=0;
        for(int i=0;i<s.size()&&t[r]!='\0';i++)
        {
            if(s[i]==t[r])
            {
                r++;
                c--;
            }
        }
        return c;
    }
};