class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) totalSum += num;

        // If the total sum is odd, it's impossible to split into two equal integers
        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2;
        
        // dp[j] will be true if sum 'j' can be reached
        vector<bool> dp(target + 1, false);
        dp[0] = true; // Base case: a sum of 0 is always possible (empty set)

        for (int num : nums) {
            // Iterate backwards to ensure we don't use the same element twice
            // if we went forwards, dp[j-num] might have been updated by 'num' already
            for (int j = target; j >= num; j--) {
                if (dp[j - num]) {
                    dp[j] = true;
                }
            }
            // Optimization: if we already found the target, we can bail early
            if (dp[target]) return true;
        }

        return dp[target];
    }
};