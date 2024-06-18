class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs;
        int n = profit.size();
        
        // Step 1: Pair the jobs with difficulty and profit
        for (int i = 0; i < n; ++i) {
            jobs.push_back({difficulty[i], profit[i]});
        }
        
        // Step 2: Sort the jobs based on difficulty, and then by profit if difficulties are the same
        sort(jobs.begin(), jobs.end());
        
        // Step 3: Sort the worker array
        sort(worker.begin(), worker.end());
        
        int maxProfit = 0;
        int best = 0;
        int i = 0;
        
        // Step 4: Iterate over each worker
        for (int ability : worker) {
            // Move the job pointer to find the most profitable job the worker can do
            while (i < n && jobs[i].first <= ability) {
                best = max(best, jobs[i].second);
                ++i;
            }
            maxProfit += best;
        }
        
        return maxProfit;
    }
};
