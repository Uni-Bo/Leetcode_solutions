class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprof=0;
        int n=prices.size();
        int buy=prices[0],prof=0;
        for(int i=1;i<n;i++)
        {
            prof=prices[i]-buy;
            if(prof>maxprof)
            {
                maxprof=prof;
            }
            else if(prof<0)
            {
                buy=prices[i];
            }
        }
        return maxprof;
    }
};