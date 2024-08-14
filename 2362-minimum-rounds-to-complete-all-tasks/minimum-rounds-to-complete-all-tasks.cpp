class Solution{
    public:
    int minimumRounds(vector<int>& tasks) {
    unordered_map<int, int> freqMap;
    
    // Count the frequency of each difficulty level
    for (int task : tasks) {
        freqMap[task]++;
    }

    int totalRounds = 0;

    // Check for each difficulty level
    for (auto& entry : freqMap) {
        int freq = entry.second;

        // If the frequency is 1, it's impossible to complete
        if (freq == 1) {
            return -1;
        }

        // Calculate minimum rounds for this frequency
        int minRounds = INT_MAX;
        if (freq % 3 == 0) {
            minRounds = min(minRounds, freq / 3);
        }
        if (freq % 3 == 1) {
            if (freq >= 4) {
                minRounds = min(minRounds, freq / 3 - 1 + 2);
            }
        }
        if (freq % 3 == 2) {
            minRounds = min(minRounds, freq / 3 + 1);
        }

        totalRounds += minRounds;
    }

    return totalRounds;
}
};