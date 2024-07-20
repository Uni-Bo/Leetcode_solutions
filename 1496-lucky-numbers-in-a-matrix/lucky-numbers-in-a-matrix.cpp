#include <vector>
#include <climits> // For INT_MAX and INT_MIN

using namespace std;

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& mat) {
        int m = mat.size(); // Number of rows
        int n = mat[0].size(); // Number of columns

        vector<int> ans;

        for (int i = 0; i < m; ++i) {
            int rowMin = INT_MAX; // Rename min to rowMin
            int colIndex = -1; // Initialize index of the maximum element in the column

            // Find the minimum element in the current row
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] < rowMin) {
                    rowMin = mat[i][j];
                    colIndex = j; // Update the index of the maximum element in the column
                }
            }

            // Check if the minimum element in the row is also the maximum element in its column
            bool isLucky = true;
            for (int k = 0; k < m; ++k) {
                if (mat[k][colIndex] > rowMin) {
                    isLucky = false;
                    break;
                }
            }

            // If the minimum element in the row is also the maximum element in its column, it's a lucky number
            if (isLucky) {
                ans.push_back(rowMin);
            }
        }

        return ans;
    }
};
