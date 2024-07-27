class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        vector<int> dp(amt+1, amt+1);
        dp[0] = 0;

        for(int i = 0; i <= amt; i++){
            for(auto coin : coins){
                if(i - coin >= 0){
                    dp[i] = min(dp[i], 1 + dp[i-coin]);
                }
            }
        }
        return dp[amt] > amt ? -1 : dp[amt];
    }
};