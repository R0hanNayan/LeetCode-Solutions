class Solution{
public:
    vector<vector<int>> dp;
    int solve(int arr[], int i, int j){
        if(i >= j)  return 0;
        if(dp[i][j] != -1)  return dp[i][j];
        
        int mini = INT_MAX;
        for(int k = i; k <= j-1; k++){
            int temp = solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1] * arr[k] * arr[j];
            mini = min(temp, mini);
        }
        return dp[i][j] = mini;
    }
    int matrixMultiplication(int n, int arr[])
    {
        dp.resize(n+1, vector<int>(n+1, -1));
        return solve(arr, 1, n-1);
    }
};
