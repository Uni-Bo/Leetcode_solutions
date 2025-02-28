class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans; 
        
        for(int n = 0; n < numRows; n++) {
            vector<int> row(n + 1, 1); // Initialize row with 1s
            
            for(int m = 1; m < n; m++) {
                row[m] = ans[n - 1][m - 1] + ans[n - 1][m]; // Compute Pascal's value
            }
            
            ans.push_back(row);
        }
        
        return ans;
    }
};
