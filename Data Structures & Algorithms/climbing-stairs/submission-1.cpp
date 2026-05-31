class Solution {
public:
    int climbStairs(int n) {
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                ans[i] = 1;
            } else if (i == 1) {
                ans[i] = 2;
            }
            else {
                ans[i] = ans[i - 1] + ans[i - 2]; 
            }
        }
        return ans[n - 1];
    }
};
