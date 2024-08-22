class Solution {
public:
    vector<vector<int>> dp;
    // int solve(string s1, string s2, int n, int m){
    //     if(n == 0 || m == 0)    return 0;
    //     if(dp[n][m] != -1)  return dp[n][m];

    //     if(s1[n-1] == s2[m-1]){
    //         dp[n][m] = 1 + solve(s1, s2, n-1, m-1);
    //     }else{
    //         dp[n][m] = max(solve(s1, s2, n-1, m), solve(s1, s2, n, m-1));
    //     }
    //     return dp[n][m];
    // }
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s.begin(), s.end());
        int n = s.size(), m = s2.size();
        dp.resize(n+1, vector<int>(m+1, 0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};