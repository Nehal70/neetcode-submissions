class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        // 1. Initial Scan
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 0) q.push({r, c}); // Push all treasures
            }
        }

        // 2. BFS Expansion
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            
            int dr[] = {0, 0, 1, -1}, dc[] = {1, -1, 0, 0};
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i], nc = c + dc[i];
                // Only visit if it's within bounds and is an empty room (often 2147483647)
                if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == 2147483647) {
                    grid[nr][nc] = grid[r][c] + 1; // Update distance
                    q.push({nr, nc});
                }
            }
        }
    }
};
