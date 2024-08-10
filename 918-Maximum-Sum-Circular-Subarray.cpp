class Solution {
public:
    int kadaneMin(vector<int>& nums){
        int mini = INT_MAX;
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            sum = min(nums[i], sum+nums[i]);
            mini = min(mini, sum);
        }
        return mini;
    }
    int kadaneMax(vector<int>& nums){
        int maxi = INT_MIN;
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            sum = max(nums[i], sum+nums[i]);
            maxi = max(maxi, sum);
        }
        return maxi;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int tSum = accumulate(nums.begin(), nums.end(), 0);
        int mini = kadaneMin(nums);
        int maxi = kadaneMax(nums);
        int circularSum = tSum - mini;

        if(maxi > 0){
            return max(maxi, circularSum);
        }
        return maxi;
    }
};