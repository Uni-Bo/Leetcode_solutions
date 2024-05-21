class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int, vector<int>, greater<int> > heap; // mean heap
        for(int i=0;i<nums.size();i++)
        {
            heap.push(nums[i]);
            if (k<heap.size())
                heap.pop();      
        }
       
        return heap.top();
    }
};