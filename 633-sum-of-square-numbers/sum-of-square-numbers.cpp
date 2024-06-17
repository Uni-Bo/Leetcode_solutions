class Solution {
public:
    bool judgeSquareSum(int c) {
        int n=(int)sqrt(c);
        if(n==sqrt(c)) return true;
        for(int i=n;i>0;i--)
        {
            int temp=c-(i*i);
            if((int)sqrt(temp)==sqrt(temp)) return true;
        }
        return false;
    }
};