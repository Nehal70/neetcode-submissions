class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                ans[i] = nums[i];
            } else if (i == 1) {
                ans[i] = (nums[i] > nums[i-1]) ? (nums[i]) : (nums[i-1]);
            } else {
                ans[i] = ((nums[i] + ans[i -2]) > (ans[i - 1]) ? (nums[i] + ans[i -2]) : (ans[i - 1]));
            }
        }
        return ans[nums.size() - 1];
    }
};
