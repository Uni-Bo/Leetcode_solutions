class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> set={arr.begin(),arr.end()};
        vector<int>unq={set.begin(),set.end()};
        sort(unq.begin(),unq.end());
        unordered_map<int,int>map;
        int i=1;
        for(auto&a:unq){
            map[a]=i;
            i++;
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=map[arr[i]];
        }
        return arr;
    }
};