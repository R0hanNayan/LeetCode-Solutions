class Solution {
  public:
    int mod = 1e9 + 7;
    vector<vector<int>> dp;
    
    int solve(int n, int s1, vector<int>& arr){
        if (n == 0) return (s1 == 0) ? 1 : 0;
        
        if(dp[n][s1] != -1) return dp[n][s1];
        
        if(s1 >= arr[n-1]){
            dp[n][s1] = solve(n-1, s1-arr[n-1], arr) % mod + solve(n-1, s1, arr) % mod;
        }else{
            dp[n][s1] = solve(n-1, s1, arr) % mod;
        }
        return dp[n][s1] % mod;
    }
    
    int countPartitions(int n, int d, vector<int>& arr) {
        int sum = 0;
        for(auto it : arr)  sum += it;
        
        if ((sum - d) < 0 || (sum - d) % 2 != 0) return 0;
        
        int s1 = (sum - d)/2;
        dp.resize(n+1, vector<int>(s1+1, -1));
        
        return solve(n, s1, arr);
    }
};
