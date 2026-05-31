class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        int minResult = INT_MAX;
        while (left <= right) {

            if (nums[left] <= nums[right]) {
                minResult = min(minResult, nums[left]);
                break;
            } 

            int middle = (left + right) / 2;
            minResult = (nums[middle] < minResult) ? (nums[middle]) : (minResult);
            if (nums[middle] < nums[left]) {
                //check left side
                right = middle - 1;
            } else if (nums[middle] > nums[right]) {
                //check right side
                left = middle + 1;
            } 
        }
        return minResult;
    }
};
