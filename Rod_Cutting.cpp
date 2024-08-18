class Solution{
  public:
    vector<int> dp;
    int solve(int price[], int n) {
        if (n <= 0) return 0;
        if(dp[n] != -1) return dp[n];
        
        int maxi = 0;
        for (int i = 1; i <= n; i++) {
            maxi = max(maxi, price[i-1] + solve(price, n - i));
        }
        
        return dp[n] = maxi;
    }
    int cutRod(int price[], int n) {
        dp.resize(n+1, -1);
        return solve(price, n);
    }
};
