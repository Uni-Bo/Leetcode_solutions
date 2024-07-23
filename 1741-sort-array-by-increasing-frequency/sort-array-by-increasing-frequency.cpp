class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) 
    {
        map<int, int> frequencies;

        for(int number: nums)
        {
            frequencies[number] += 1;
        }

        vector<pair<int, int>> frequencyPairs(frequencies.begin(), frequencies.end());
    
    
        sort(frequencyPairs.begin(), frequencyPairs.end(), [=](pair<int, int> a, pair<int, int> b) 
        {
            if (a.second == b.second) 
                return a.first > b.first;
            
            return a.second < b.second;
        });

        vector<int> sortedElements;
        for (auto& [num, count] : frequencyPairs) 
        {
            for (int i = 0; i < count; ++i) 
            {
                sortedElements.push_back(num);
            }
        }

        return sortedElements;


        
    }
};