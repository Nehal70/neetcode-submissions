class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int curMax = 1, curMin = 1;
        
        for (int n : nums) {
            // If n is negative, swapping max and min handles the sign flip
            if (n < 0) swap(curMax, curMin);
            
            curMax = max(n, curMax * n);
            curMin = min(n, curMin * n);
            
            res = max(res, curMax);
        }
        return res;
    }
};
