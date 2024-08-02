class Solution {
public:
    int lowerbound(vector<int>& nums, int t){
        int n = nums.size();
        int l = 0, h = n-1;
        int ans = n;
        while(l <= h){
            int m = l + (h - l)/2;
            if(nums[m] >= t){
                ans = m;
                h = m - 1;
            }else{
                l = m + 1;
            }
        }
        return ans;
    }
    int upperbound(vector<int>& nums, int t){
        int n = nums.size();
        int l = 0, h = n-1;
        int ans = n;
        while(l <= h){
            int m = l + (h - l)/2;
            if(nums[m] > t){
                ans = m;
                h = m - 1;
            }else{
                l = m + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int t) {
        int n = nums.size();
        int lb = lowerbound(nums, t);
        int ub = upperbound(nums, t);
        if(lb == n || nums[lb] != t){
            return {-1, -1};
        }
        return {lb, ub-1};
    }
};