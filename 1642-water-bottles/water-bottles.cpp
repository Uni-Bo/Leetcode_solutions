
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int empty = 0;

        while (numBottles > 0) {
            ans += numBottles; // Add the number of full bottles to the total
            empty += numBottles; // Update the number of empty bottles
            numBottles = empty / numExchange; // Exchange empty bottles for full ones
            empty = empty % numExchange; // Update the remaining empty bottles after exchange
        }

        return ans;
    }
};