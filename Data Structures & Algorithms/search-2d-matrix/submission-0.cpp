class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix.size() * matrix[0].size() - 1;
        while (left <= right) {
            int middle = ((left + right) / 2);
            int row = (middle / matrix[0].size());
            int rowIndex = middle % matrix[0].size();
            if (target < matrix[row][rowIndex]) {
                right = (row * matrix[0].size() + rowIndex - 1);
            } else if (target > matrix[row][rowIndex]) {
                left = (row * matrix[0].size() + rowIndex + 1);
            } else {
                return true;
            }
        }
        return false;
    }
};
