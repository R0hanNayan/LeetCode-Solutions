class Solution{
	public:
	int mod = 1e9+7;
	int solve(int arr[], int n, int sum, vector<vector<int>> &dp){
	    if(n == 0 && sum == 0) return 1;
	    if(n == 0 && sum != 0)  return 0;
	    
	    if(dp[n][sum] != -1)    return dp[n][sum];
	    
	    if(arr[n-1] <= sum){
	        dp[n][sum] = solve(arr, n-1, sum-arr[n-1], dp) % mod + solve(arr, n-1, sum, dp) % mod;
	    }else{
	        dp[n][sum] = solve(arr, n-1, sum, dp) % mod;
	    }
	    
	    return dp[n][sum] % mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        return solve(arr, n, sum, dp) % mod;
	}
	  
};
