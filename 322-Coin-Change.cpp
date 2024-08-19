class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& coins, int amt, int n){
        if(amt == 0)  return 0;
        if(n == 0 || amt < 0)  return INT_MAX - 1;
        if(dp[n][amt] != -1)  return dp[n][amt];

        int once = solve(coins, amt, n-1);
        int twice = 1 + solve(coins, amt - coins[n-1], n);
        dp[n][amt] = min(once, twice);
        return dp[n][amt];
    }
    int coinChange(vector<int>& coins, int amt) {
        int n = coins.size();
        dp.resize(n+1, vector<int>(amt+1, -1));
        int ans = solve(coins, amt, n);
        return (ans >= INT_MAX-1) ? -1 : ans;
    }
};