class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> prefixModCount;
        prefixModCount[0] = 1; // There is one way to have a sum of 0 (empty subarray)
        int count = 0;
        int prefixSum = 0;

        for (int num : nums) {
            prefixSum += num;
            int mod = ((prefixSum % k) + k) % k; // Ensure the modulus is non-negative

            if (prefixModCount.find(mod) != prefixModCount.end()) {
                count += prefixModCount[mod];
            }
            
            // Increment the count of this mod in the map
            prefixModCount[mod]++;
        }

        return count;
    }
};
