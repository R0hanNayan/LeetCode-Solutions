class Solution{
  public:
    vector<vector<int>> dp;
    int solve(int i, int s1, int &sum, int arr[], int n){
        if(i == n){
            int s2 = sum - s1;
            return abs(s1 - s2);
        }
        
        if(dp[i][s1] != -1)    return dp[i][s1];
        
        int take = solve(i+1, s1 + arr[i], sum, arr, n);
        int nTake = solve(i+1, s1, sum, arr, n);
                                
        return dp[i][s1] = min(take, nTake);
    }
    
	int minDifference(int arr[], int n)  { 
	    int sum = 0;
	    for(int i=0; i<n; i++){
	        sum += arr[i];
	    }
	    
	    dp.resize(n, vector<int>(sum+1, -1));
	    return solve(0, 0, sum, arr, n);
	} 
};
