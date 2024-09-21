class Solution {
public:
    void solve(int i, int n,vector<int>& ans){
        if(i>n) return;
        if(i>0) ans.push_back(i);
        for(int j=(i==0)?1:0;j<=9;j++){
            int x=10*i+j;
            if(x>n) return;
            solve(x,n,ans);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        solve(0,n,ans);
        return ans;
    }
};