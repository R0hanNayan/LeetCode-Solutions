class Solution {\r
public:\r
    long long maxAlternatingSum(vector<int>& nums) {\r
        int n = nums.size();\r
        vector<vector<long long>> dp(n+1, vector<long long>(2, 0));\r
        \r
        for(int i = 1; i <= n; i++){\r
            dp[i][0] = max(dp[i-1][1] - nums[i-1], dp[i-1][0]);\r
            dp[i][1] = max(dp[i-1][0] + nums[i-1], dp[i-1][1]);\r
        }\r
\r
        return max(dp[n][0], dp[n][1]);\r
    }\r
};