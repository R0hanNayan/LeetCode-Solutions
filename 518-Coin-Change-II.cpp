class Solution {
public:
    vector<vector<int>> dp;
    int solve(int amt, vector<int>& coins, int n){
         if(amt == 0)  return 1;
        if(n == 0 || amt < 0)  return 0;
        if(dp[n][amt] != -1)    return dp[n][amt];

        int once = solve(amt, coins, n-1);
        int twice = solve(amt-coins[n-1], coins, n);
        
        return dp[n][amt] = once + twice;
    }
    int change(int amt, vector<int>& coins) {
        int n = coins.size();
        dp.resize(n+1, vector<int>(amt+1, -1));
        return solve(amt, coins, n);
    }
};