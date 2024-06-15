#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects(n);
        for (int i = 0; i < n; ++i) {
            projects[i] = {capital[i], profits[i]};
        }
        sort(projects.begin(), projects.end());
        
        priority_queue<int> maxProfitQueue;
        int index = 0;
        
        while (k > 0) {
            while (index < n && projects[index].first <= w) {
                maxProfitQueue.push(projects[index].second);
                ++index;
            }
            if (!maxProfitQueue.empty()) {
                w += maxProfitQueue.top();
                maxProfitQueue.pop();
                --k;
            } else {
                break;
            }
        }
        
        return w;
    }
};
