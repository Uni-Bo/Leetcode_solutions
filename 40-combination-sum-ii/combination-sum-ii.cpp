class Solution {
public:
    void help(vector<int>& candidates, vector<int>& curr, vector<vector<int>>& ans, int target, int i) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        if (i >= candidates.size() || target < 0) {
            return;
        }
        
        // Include the current element
        curr.push_back(candidates[i]);
        help(candidates, curr, ans, target - candidates[i], i + 1);
        curr.pop_back();
        
        // Skip over duplicates
        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
            i++;
        }

        // Exclude the current element
        help(candidates, curr, ans, target, i + 1);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        
        // Sort candidates to handle duplicates efficiently
        sort(candidates.begin(), candidates.end());
        
        // Start recursive helper function
        help(candidates, curr, ans, target, 0);
        
        return ans;
    }
};
