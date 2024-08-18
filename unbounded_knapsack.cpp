class Solution{
public:
    vector<vector<int>> dp;
    int solve(int n, int w, int val[], int wt[]){
        if(n == 0 || w == 0)    return 0;
        if(dp[n][w] != -1)  return dp[n][w];
        
        if(wt[n-1] <= w){
            dp[n][w] = max(val[n-1] + solve(n, w-wt[n-1], val, wt), solve(n-1, w, val, wt));
        }else{
            dp[n][w] = solve(n-1, w, val, wt);
        }
        return dp[n][w];
    }
    int knapSack(int n, int w, int val[], int wt[])
    {
        dp.resize(n+1, vector<int>(w+1, -1));
        return solve(n, w, val, wt);
    }
};
