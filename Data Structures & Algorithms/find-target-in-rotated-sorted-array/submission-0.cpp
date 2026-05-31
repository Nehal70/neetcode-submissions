class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (nums[middle] == target) return middle;
            if (nums[left] > nums[middle]) {
                //pivot on left
                //check if in right range
                if (nums[middle] < target && nums[right] >= target) {
                    //yes in right range
                    left  = middle + 1;
                } else {
                    //in left range
                    right = middle - 1;
                }
            } else if (nums[right] < nums[middle]) {
                //pivot on right
                if (nums[middle] > target && nums[left] <= target) {
                    //yes in left range
                    right  = middle - 1;
                } else {
                    //in right range
                    left = middle + 1;
                }
            } else { // 
                //already ordered
                if (nums[middle] > target) {
                    //search left
                    right = middle - 1;
                } else if (nums[middle] < target) {
                    left = middle + 1;
                } else {
                    return middle;
                }
            }
        }
        return -1;
    }
};
