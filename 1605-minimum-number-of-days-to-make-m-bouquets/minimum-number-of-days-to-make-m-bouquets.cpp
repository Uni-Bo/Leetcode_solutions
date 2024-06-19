#include <vector>
#include <algorithm>

class Solution {
public:
    bool canMakeBouquets(const std::vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0;
        int flowers = 0;

        for (int bloom : bloomDay) {
            if (bloom <= day) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
            if (bouquets >= m) {
                return true;
            }
        }
        return bouquets >= m;
    }

    int minDays(std::vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (static_cast<long long>(m) * k > n) return -1; // Not enough flowers to make the bouquets

        int left = *std::min_element(bloomDay.begin(), bloomDay.end());
        int right = *std::max_element(bloomDay.begin(), bloomDay.end());

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canMakeBouquets(bloomDay, m, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
