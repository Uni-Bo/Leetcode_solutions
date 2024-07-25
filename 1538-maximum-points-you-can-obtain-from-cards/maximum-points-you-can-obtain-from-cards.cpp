class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int totalSum = 0;

        // Calculate the sum of the first k cards
        for (int i = 0; i < k; ++i) {
            totalSum += cardPoints[i];
        }

        // This is the maximum sum initially
        int maxScore = totalSum;

        // Sliding window to consider cards from the end
        for (int i = 0; i < k; ++i) {
            // Subtract the ith card from the start and add the ith card from the end
            totalSum = totalSum - cardPoints[k - 1 - i] + cardPoints[n - 1 - i];
            maxScore = max(maxScore, totalSum);
        }

        return maxScore;
    }
};
