class Solution {
public:
    void helper(vector<int>& nums, int& sum, int currentXOR, int i) {
        if (i == nums.size()) {
            sum += currentXOR;
            return;
        }
        helper(nums, sum, currentXOR ^ nums[i], i + 1);//take
        helper(nums, sum, currentXOR, i + 1);//dont take
    }

    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        helper(nums, sum, 0, 0);
        return sum;
    }
};
