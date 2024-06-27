class Solution {
public:
    int findCenter(vector<vector<int>>& edge) {
        unordered_map<int,int>count;
        {
            for(int i=0;i<2;i++)
            {
                count[edge[i][0]]++;
                count[edge[i][1]]++;
            }
        }
        for(auto& it:count)
        {
            if(it.second>=2)
                return it.first;
        }
        return -1;
    }
};