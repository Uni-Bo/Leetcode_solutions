class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n=names.size();
        vector<pair<int,string>>temp;
        for(int i=0;i<n;i++)
        {
            temp.push_back({heights[i],names[i]});
        }
        sort(temp.begin(),temp.end());
        for(int i=n-1;i>=0;i--)
        {
            names[n-i-1]=temp[i].second;
        }
        return names;
    }
};