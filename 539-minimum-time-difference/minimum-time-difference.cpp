class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> time;
        
        // Convert each time point to minutes and store in time vector
        for (auto t : timePoints) {
            int pos = t.find(":");
            int hr = stoi(t.substr(0, pos));              // Extract the hour part
            int min = stoi(t.substr(pos + 1));            // Extract the minute part
            time.push_back(hr * 60 + min);                // Convert to total minutes
        }
        
        // Sort the time vector to easily calculate minimum difference
        sort(time.begin(), time.end());
        
        int minDiff = INT_MAX;
        int n = time.size();
        
        // Find minimum difference between consecutive times
        for (int i = 1; i < n; i++) {
            minDiff = min(minDiff, time[i] - time[i - 1]);
        }
        
        // Handle the circular case (between the first and last time points)
        int circularDiff = (24 * 60 - time[n - 1] + time[0]);
        minDiff = min(minDiff, circularDiff);
        
        return minDiff;
    }
};
