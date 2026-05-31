class Solution {
public:
    void sortColors(vector<int>& nums) {

        int low = 0; int mid = 0; int high = nums.size() - 1;

        while (mid <= high) {

            // mid is where the next 1 should go
            // low is where the next 0 should go
            // high is where the next 2 should go

            if (nums[mid] == 0) {
                //swap
                nums[mid] = nums[low];
                nums[low] = 0;
                //update
                mid++;
                low++;
            } else if (nums[mid] == 1) {
                mid++; //Update mid for the next 1
            } else {
                //swap w/ high and update
                nums[mid] = nums[high];
                nums[high] = 2;
                //update
                high--;
            }
        }

    }
};