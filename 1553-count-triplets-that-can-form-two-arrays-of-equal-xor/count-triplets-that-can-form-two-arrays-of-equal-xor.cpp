class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] ^ arr[i];
        }
        
        unordered_map<int, int> count;
        unordered_map<int, int> total;
        int result = 0;
        
        for (int k = 0; k < n; ++k) {
            if (count.find(prefix[k + 1]) != count.end()) {
                result += count[prefix[k + 1]] * k - total[prefix[k + 1]];
            }
            count[prefix[k]]++;
            total[prefix[k]] += k;
        }
        
        return result;
    }
};
