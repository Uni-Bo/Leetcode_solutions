class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n=customers.size();
        double s=0;
        int end=0,arrive=0;
        for(int i=0;i<n;i++)
        {
            arrive=customers[i][0];
            if(end>arrive)
            {
                customers[i][0]+=end-arrive;
            }
            end=customers[i][0]+customers[i][1];
            s+=end-arrive;
        }
        return s/n;
    }
};