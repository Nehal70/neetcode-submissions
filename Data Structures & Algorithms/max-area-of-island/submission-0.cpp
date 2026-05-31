class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    int area = dfs(grid, i, j);
                    maxArea = (area > maxArea) ? (area) : (maxArea);
                }
            }
        }
        return maxArea;
    }

    int dfs(vector<vector<int>>& grid, int row, int col) {
        //edge cases
        if (row >= grid.size() || col >= grid[0].size()) {
            return 0;
        } 
        if (row < 0 || col < 0) {
            return 0;
        }
        //is it a piece of land?
        if (grid[row][col] == 0) {
            //no
            return 0;
        } 

        //yes - mark it as explored
        int area = 1;
        grid[row][col] = 0;
        int deltaRow[] = {-1, 1, 0, 0};
        int deltaCol[] = {0, 0, -1, 1};
        for (int it = 0; it < 4; it++) {
            area += dfs(grid, row + deltaRow[it], col + deltaCol[it]);
        }

        return area;
    }
};
