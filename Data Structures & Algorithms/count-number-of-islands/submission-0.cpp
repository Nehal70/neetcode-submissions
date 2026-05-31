class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numIslands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs (grid, i, j);
                    numIslands += 1;
                }
            }
        }
        return numIslands;
    }

    void dfs(vector<vector<char>>& grid, int i, int j) {
        //base cases
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') {
            return;
        } 
        //mark as explored
        grid[i][j] = '0';
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for (int r = 0; r < 4; r++) {
            dfs(grid, i + dr[r], j + dc[r]);
        }
    }
};
