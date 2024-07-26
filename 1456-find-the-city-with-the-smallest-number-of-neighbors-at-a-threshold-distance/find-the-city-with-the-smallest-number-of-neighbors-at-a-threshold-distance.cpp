#include <vector>
#include <climits>

class Solution {
public:
    int findTheCity(int n, std::vector<std::vector<int>>& edges, int distanceThreshold) {
        // Initialize distance matrix
        std::vector<std::vector<int>> dist(n, std::vector<int>(n, INT_MAX / 2));
        for (int i = 0; i < n; ++i)
            dist[i][i] = 0;
        
        // Fill the distance matrix with given edges
        for (const auto& edge : edges) {
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }

        // Floyd-Warshall algorithm to find shortest paths between all pairs of nodes
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        // Find the city with the smallest number of neighbors within the distance threshold
        int minNeighbors = INT_MAX;
        int resultCity = -1;
        
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    ++count;
                }
            }
            
            if (count < minNeighbors) {
                minNeighbors = count;
                resultCity = i;
            } else if (count == minNeighbors && i > resultCity) {
                resultCity = i;
            }
        }

        return resultCity;
    }
};
