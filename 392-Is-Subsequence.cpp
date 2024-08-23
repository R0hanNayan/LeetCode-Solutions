class Solution {
public:
    bool isSubsequence(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

        for(int j = 0; j <= m; j++){
            dp[0][j] = true;
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[n-1] == p[m-1]){
                    dp[n][m] = dp[i-1][j-1];
                }else{
                    dp[n][m] = dp[i-1][j] || dp[i][j-1];
                }
            }
        }
        return dp[n][m];
    }
};