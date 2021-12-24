class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price {prices[0]};
        int max_profit {0};
        
        for (size_t i = 1; i < prices.size(); ++i) {
            if ((prices[i] - min_price) > max_profit) {
                max_profit = prices[i] - min_price;
            }
            if (prices[i] < min_price) {
                min_price = prices[i];
            }
        }
        return max_profit;
    }
};
