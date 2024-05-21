class Solution {
public:
void reverseStr(string& str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}
    string reversePrefix(string word, char ch) {
        int i,f=0;
        for(i=0;i<word.size();i++)
        {
            if(word[i]==ch)
            {
                f=1;
                break;
            }
        }
        if(f==0) return word;
        string rev=word.substr(0,++i);
        reverseStr(rev);
        string rest=word.substr(i,word.size()-1);
        string str=rev+rest;
        return str;
    }
};