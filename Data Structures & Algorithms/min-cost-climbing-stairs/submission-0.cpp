class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> ans(cost.size() + 1);
        for (int i = 0; i <= cost.size(); i++) {
            if (i == 0) {
                ans[i] = 0;
            } else if (i == 1) {
                ans[i] = 0;
            } else {
                ans[i] = ((ans[i - 2] + cost[i - 2]) < (ans[i - 1] + cost[i - 1])) ? (ans[i - 2] + cost[i - 2]) : (ans[i - 1] + cost[i - 1]);
            }
        }
        return ans[cost.size()];
    }
};
