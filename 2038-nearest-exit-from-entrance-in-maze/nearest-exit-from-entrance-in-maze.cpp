#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution { 
public:

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        // Use a queue to perform BFS. Each entry holds (row, col) and the number of steps so far.
        queue<pair<pair<int,int>, int>> q;
        int startRow = entrance[0], startCol = entrance[1];
        q.push({{startRow, startCol}, 0});
        // Mark the entrance as visited so we do not return it as an exit.
        maze[startRow][startCol] = '+';
        
        // Directions: down, up, right, left.
        vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int row = cur.first.first;
            int col = cur.first.second;
            int steps = cur.second;
            
            for (auto d : directions) {
                int newRow = row + d.first;
                int newCol = col + d.second;
                
                // Skip positions that are out-of-bounds.
                if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n)
                    continue;
                // Skip walls or cells already visited.
                if (maze[newRow][newCol] == '+')
                    continue;
                // If the new cell is on the maze border, it is an exit.
                if (newRow == 0 || newRow == m-1 || newCol == 0 || newCol == n-1)
                    return steps + 1;
                
                // Mark this cell as visited and add it to the queue.
                maze[newRow][newCol] = '+';
                q.push({{newRow, newCol}, steps + 1});
            }
        }
        return -1; // No exit found.
    }
};
