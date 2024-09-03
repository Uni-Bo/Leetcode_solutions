class Solution {
public:
    int getLucky(string s, int k) {
        int i=0;
        string str;
        for(i=0;i<s.size();i++)
        {
            str+=to_string((int)(s[i]-'a')+1);
        }
        int x=0;
        while(k--){
            x=0;
            for(int j=0;j<str.size();j++)
            {
                x+=str[j]-'0';
            }
            str=to_string(x);
        }
    return x;
    }
};