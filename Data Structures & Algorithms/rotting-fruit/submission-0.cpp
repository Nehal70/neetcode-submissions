#include <queue>

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int freshCount = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        // 1. Initial Scan: Find all rotten oranges and count fresh ones
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        // If no fresh oranges, it takes 0 minutes
        if (freshCount == 0) return 0;

        int minutes = 0;
        int deltaRow[] = {1, -1, 0, 0};
        int deltaCol[] = {0, 0, 1, -1};

        // 2. BFS: Process by "minutes" (layers)
        while (!q.empty() && freshCount > 0) {
            int levelSize = q.size(); // Number of oranges rotting this minute
            minutes++;

            for (int k = 0; k < levelSize; k++) {
                pair<int, int> curr = q.front();
                q.pop();

                for (int it = 0; it < 4; it++) {
                    int ni = curr.first + deltaRow[it];
                    int nj = curr.second + deltaCol[it];

                    // Only rot if in bounds and the orange is fresh
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && grid[ni][nj] == 1) {
                        grid[ni][nj] = 2; // Mark as rotten immediately
                        freshCount--;
                        q.push({ni, nj});
                    }
                }
            }
        }

        // 3. Final Check: If freshCount > 0, some oranges never rot
        return (freshCount == 0) ? minutes : -1;
    }
};