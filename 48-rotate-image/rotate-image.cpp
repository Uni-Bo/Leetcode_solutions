class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size(),i,j;
        vector<vector<int>> temp=matrix;
        for(i=n-1;i>=0;i--)
        {
            for(j=0;j<n;j++)
            {
                matrix[j][n-i-1]=temp[i][j];
            }
        }

    }
};