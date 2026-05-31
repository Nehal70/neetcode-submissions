class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};
        int rows = heights.size();
        int cols = heights[0].size();
        
        vector<vector<bool>> reachPacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> reachAtlantic(rows, vector<bool>(cols, false));
        queue<pair<int, int>> bfsQueue;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                    // Bordering cell logic
                    if (i == 0 || j == 0) {
                        reachPacific[i][j] = true;
                    } 
                    if (i == rows - 1 || j == cols - 1) {
                        reachAtlantic[i][j] = true;
                    }
                    bfsQueue.push({i, j});
                }
            }
        }

        // BFS traversal
        while (!bfsQueue.empty()) {
            pair<int, int> curr = bfsQueue.front(); 
            bfsQueue.pop();
            
            int r = curr.first;
            int c = curr.second;
            
            int deltaRow[] = {0, 0, -1, 1};
            int deltaCol[] = {-1, 1, 0, 0};
            
            for (int k = 0; k < 4; k++) {
                int newRow = r + deltaRow[k]; 
                int newCol = c + deltaCol[k];
                
                if (newRow >= 0 && newCol >= 0 && newRow < rows && newCol < cols && heights[newRow][newCol] >= heights[r][c]) {
                    // Check if this neighbor actually needs updating to prevent infinite loops
                    bool updated = false;
                    if (reachPacific[r][c] && !reachPacific[newRow][newCol]) {
                        reachPacific[newRow][newCol] = true;
                        updated = true;
                    }
                    if (reachAtlantic[r][c] && !reachAtlantic[newRow][newCol]) {
                        reachAtlantic[newRow][newCol] = true;
                        updated = true;
                    }
                    
                    if (updated) {
                        bfsQueue.push({newRow, newCol});
                    }
                } 
            }
        }

        vector<vector<int>> result;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (reachPacific[i][j] && reachAtlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};