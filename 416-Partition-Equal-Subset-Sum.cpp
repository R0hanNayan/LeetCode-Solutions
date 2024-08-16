class Solution {
public:
    bool solve(vector<int>& nums, int n, int sum, vector<vector<int>> &dp){
        if(sum == 0)  return true;
        if(n == 0)  return false;
        if(dp[n][sum] != -1)    return dp[n][sum];

        if(nums[n-1] <= sum){
            dp[n][sum] = solve(nums, n-1, sum-nums[n-1], dp) || solve(nums, n-1, sum, dp);
        }else{
            dp[n][sum] = solve(nums, n-1, sum, dp);
        }

        return dp[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it : nums){
            sum += it;
        }
        if(sum % 2 != 0){
            return false;
        }

        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(sum/2+1, -1));

        return solve(nums, n, sum/2, dp);
    }
};