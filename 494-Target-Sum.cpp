class Solution {
public:
    int solve(vector<int>& nums, int n, int sum, vector<vector<int>>& dp) {
        if(n == 0) return sum == 0 ? 1 : 0;

        if(dp[n][sum] != -1) return dp[n][sum];
        
        if(nums[n - 1] <= sum){
            dp[n][sum] = solve(nums, n - 1, sum - nums[n - 1], dp) + solve(nums, n - 1, sum, dp);
        }else{
            dp[n][sum] = solve(nums, n - 1, sum, dp);
        }
        
        return dp[n][sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(), sum = 0;
        for(auto &it : nums) 
            sum += it;

        if((sum - target) % 2 != 0 || (sum - target) < 0)   return 0;
        
        int s1 = (sum - target) / 2;
        vector<vector<int>>dp(n+1, vector<int>(s1+1, -1));
        
        return solve(nums, n, s1, dp);
    }
};