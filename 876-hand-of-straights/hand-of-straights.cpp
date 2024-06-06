class Solution {
public:
    bool isNStraightHand(std::vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;

        unordered_map<int, int> map;
        priority_queue<int, vector<int>,greater<int>> heap;
        
        for (auto card : hand) {
            map[card]++;
        }
        for (auto& pair : map) {
            heap.push(pair.first);
        }

        while (!heap.empty()) {
            int first=heap.top();
            for (int i=0; i < groupSize; ++i) {
                int curr=first + i;
                if (map[curr]==0) return false;
                map[curr]--;
                if (map[curr]==0) {
                    if (curr!=heap.top()) return false; 
                    heap.pop();
                }
            }
        }
        return true;
    }
};
