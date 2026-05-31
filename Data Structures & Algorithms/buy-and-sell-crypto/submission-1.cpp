class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int resultProfit = 0;
        int minPrice = prices[0];
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] - minPrice > resultProfit) {
                resultProfit = prices[i] - minPrice;
            }
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } 
        }
        return resultProfit;
    }
};
