class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int count = 0;
        vector<int> subset;
        sort(nums.begin(), nums.end());  // Sorting helps to manage conditions easily
        backtrack(nums, k, 0, subset, count);
        return count;
    }

private:
    void backtrack(vector<int>& nums, int k, int start, vector<int>& subset, int& count) {
        if (!subset.empty()) {
            count++;  // Count the current subset if it's not empty
        }
        for (int i = start; i < nums.size(); i++) {
            // Check if we can add nums[i] to the subset without violating the condition
            bool canAdd = true;
            for (int num : subset) {
                if (abs(num - nums[i]) == k) {
                    canAdd = false;
                    break;
                }
            }
            if (canAdd) {
                subset.push_back(nums[i]);
                backtrack(nums, k, i + 1, subset, count);
                subset.pop_back();  // Backtrack
            }
        }
    }
};
