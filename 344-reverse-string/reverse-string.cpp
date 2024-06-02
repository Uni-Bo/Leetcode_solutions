class Solution {
public:
    void reverseString(vector<char>& s) {
        char t;
        int n=s.size()-1;
        cout<<n;
        for(int i=0;i<(n)/2+1;i++){
            t=s[i];
            s[i]=s[n-i];
            s[n-i]=t;
        }
        
    }
};