class Solution{
	public:
	vector<vector<int>> dp;
	int solve(string s1, string s2, int n, int m){
	    if(n == 0 || m == 0)    return 0;
	    if(dp[n][m] != -1)  return dp[n][m];
	    
	    if(s1[n-1] == s2[m-1]){
	        dp[n][m] = 1 + solve(s1, s2, n-1, m-1);
	    }else{
	        dp[n][m] = max(solve(s1, s2, n-1, m), solve(s1, s2, n, m-1));
	    }
	    return dp[n][m];
	}
	int minOperations(string s1, string s2) 
	{ 
	    int n = s1.size(), m = s2.size();
	    dp.resize(n+1, vector<int>(m+1, -1));
	    int lcs = solve(s1, s2, n, m);
	    
	    int insertion = n - lcs;
	    int deletion = m - lcs;
	    
	    return insertion + deletion;
	} 
};
