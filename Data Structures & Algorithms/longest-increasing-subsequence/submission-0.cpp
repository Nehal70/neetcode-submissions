class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans(nums.size());
        ans[0] = 1;
        int maxIndex = 0;
        for (int i = 1; i < nums.size(); i++) {
            int maxSub = -1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && ans[j] > ans[maxSub]) {
                    maxSub = j;
                }
            }
            ans[i] = (maxSub == -1) ? (1) : ans[maxSub] + 1;
            if (ans[i] > ans[maxIndex]) {
                maxIndex = i;
            }
        }
        return ans[maxIndex];
    }
};
