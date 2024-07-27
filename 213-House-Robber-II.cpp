class Solution {
public:
    int helper(vector<int> &nums){
        int n = nums.size();
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = nums[0];

        for(int i=2; i<=n; i++){
            int take = nums[i-1] + dp[i-2];
            int nTake = dp[i-1];
            dp[i] = max(take, nTake);
        }
        return dp[n];
    }
    int rob(vector<int>& nums) {
        vector<int> nums1;
        vector<int> nums2;
        int n = nums.size();
        if(n == 1)  return nums[0];
        
        for(int i=0; i<n; i++){
            if(i != n-1)  nums1.push_back(nums[i]);
            if(i != 0)  nums2.push_back(nums[i]);
        }

        int res1 = helper(nums1);
        int res2 = helper(nums2);
        return max(res1, res2);
    }
};