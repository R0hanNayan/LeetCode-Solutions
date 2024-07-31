class Solution {
public:
    // bool f(string s1, string s2, string s3, int i, int j, int k){
    //     if(i == n1 && j == n2 && k == n3)   return true;
    //     if(k >= n3) return false;

    //     bool res = false;
    //     if(s1[i] == s3[k])  res = f(s1, s2, s3, i+1, j, k+1);
    //     if(s2[j] == s3[k])  res = f(s1, s2, s3, i, j+1, k+1);

    //     return res;
    // }

    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if (n1 + n2 != n3) return false;

        vector<vector<vector<bool>>> dp(n1+1, vector<vector<bool>>(n2+1, vector<bool>(n3+1, false)));
        dp[0][0][0] = true;

        for(int i = 0; i <= n1; i++){
            for(int j = 0; j <= n2; j++){
                for(int k = 0; k <= n3; k++){
                    if (i > 0 && k > 0 && s1[i - 1] == s3[k - 1] && dp[i - 1][j][k - 1]) {
                        dp[i][j][k] = true;
                    }
                    if (j > 0 && k > 0 && s2[j - 1] == s3[k - 1] && dp[i][j - 1][k - 1]) {
                        dp[i][j][k] = true;
                    }
                }
            }
        }
        return dp[n1][n2][n3];
    }
};