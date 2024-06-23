#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDeque, minDeque;
        int left = 0;
        int maxLength = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            // Maintain the maxDeque in decreasing order
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[right]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(right);
            
            // Maintain the minDeque in increasing order
            while (!minDeque.empty() && nums[minDeque.back()] >= nums[right]) {
                minDeque.pop_back();
            }
            minDeque.push_back(right);
            
            // Check the current window
            while (nums[maxDeque.front()] - nums[minDeque.front()] > limit) {
                if (maxDeque.front() == left) {
                    maxDeque.pop_front();
                }
                if (minDeque.front() == left) {
                    minDeque.pop_front();
                }
                ++left;
            }
            
            // Update the maxLength
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};
