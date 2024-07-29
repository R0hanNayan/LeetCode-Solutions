class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for(int i=0; i<n; i++){
            dp[i][i] = true;    //substring of len 1 is always a palindrome
        }
        int mLen = 1;
        int ind = 0;

        for(int l = 2; l <= n; l++){
            for(int i = 0; i < n - l + 1; i++){
                int j = i + l -1;
                if(s[i] == s[j] && l == 2){
                    dp[i][j] = true;
                    mLen = 2;
                    ind = i;
                }else if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                    if(mLen < j - i + 1){
                        mLen = j - i + 1;
                        ind = i;
                    }
                }
            }
        }
        return s.substr(ind, mLen);
    }
};