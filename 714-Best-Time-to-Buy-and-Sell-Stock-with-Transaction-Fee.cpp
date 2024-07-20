class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int profit = 0;
        int buy = INT_MIN;

        for(int price : prices){
            buy = max(buy, profit - price);
            profit = max(profit, buy+price-fee);
        }

        return profit;
    }
};