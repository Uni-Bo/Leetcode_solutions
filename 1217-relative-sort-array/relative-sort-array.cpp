class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> map;
        for(int i=0;i<arr1.size();i++)
        {
            map[arr1[i]]++;
        }
        vector<int>ans;
        vector<int>ans1;
        for(int i=0;i<arr2.size();i++)
        {
            for(int j=0;j<map[arr2[i]];j++)
                ans.push_back(arr2[i]);
            map[arr2[i]]=-1;
        }
        for(auto& it:map)
        {
            if(it.second!=-1)
            {
                for(int j=0;j<it.second;j++)
                ans1.push_back(it.first);
            }
        }
        sort(ans1.begin(),ans1.end());
        ans.insert(ans.end(),ans1.begin(),ans1.end());
        return ans;
    }
};