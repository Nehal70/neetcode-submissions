class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        int max_pos = nums[i]; //max place u can be at rn
        while (i <= max_pos)
        {
            int curr_pos = i + nums[i]; //you can go till here
            max_pos = (max_pos < curr_pos) ? (curr_pos) : (max_pos); //new max_pos
            if (max_pos >= (nums.size() - 1)) {
                return true;
            }
            i++;
        }
        return false;
    }
};
