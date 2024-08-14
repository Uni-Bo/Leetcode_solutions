class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>count;
        int ans=0;
        for(auto& t:tasks)
        {
            count[t]++;
        }
        for(auto& c:count)
        {            
            if(c.second%3==0)
                ans+=c.second/3;
            else if(c.second%3==2)
                ans+=c.second/3+1;
            else if(c.second>6 && c.second%3==1)
                ans+=c.second/3 +1;
            else if(c.second%2==0)
                ans+=c.second/2;
            else
                return -1;
        }
        return ans;
    }
};