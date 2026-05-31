class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<int> ans(amount + 1);
        for (int i = 1; i <= amount; i++) {
            //current amount = i;
            int prevMin = INT_MAX;
            for (int j = 0; j < coins.size(); j++) {
                if ((i >= coins[j]) && ans[i - coins[j]] < prevMin) {
                    if (ans[i - coins[j]] != -1) {
                        prevMin = ans[i - coins[j]];
                    }
                }
            }
            if (prevMin == INT_MAX) {
                ans[i] = -1;
            } else {
                ans[i] = prevMin + 1;
            }
        }
        return ans[amount] ? ans[amount] : -1;
    }
};
