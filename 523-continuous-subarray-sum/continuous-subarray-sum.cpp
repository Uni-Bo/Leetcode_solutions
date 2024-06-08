class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // Use a hashmap to store the remainder of the cumulative sum
        unordered_map<int, int> remainderIndexMap;
        remainderIndexMap[0] = -1; // Handle edge case where the subarray starts from index 0
        int cumulativeSum = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            cumulativeSum += nums[i];
            int remainder = cumulativeSum % k;
            if (remainderIndexMap.find(remainder) != remainderIndexMap.end()) {
                if (i - remainderIndexMap[remainder] > 1) {
                    return true;
                }
            } else {
                remainderIndexMap[remainder] = i;
            }
        }
        
        return false;
    }
};
