class Solution {
public:
    vector<vector<int>> dp;
    int solve(int n, int currA, int clip){
        if(currA == n)  return 0;
        if(currA > 1000)  return 1000;
        if(dp[currA][clip] != -1)   return dp[currA][clip];

        int copyPaste = 2 + solve(n, currA + currA, currA);
        int paste = 1 + solve(n, currA + clip, clip);

        return dp[currA][clip] = min(copyPaste, paste);
    }
    int minSteps(int n) {
        dp.resize(1001, vector<int>(1001, -1));
        if(n == 1)  return 0;
        return 1 + solve(n, 1, 1);
    }
};