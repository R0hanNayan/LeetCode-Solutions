class Solution {
public:
    int searchInsert(vector<int>& nums, int t) {
        int n = nums.size();
        int l = 0, h = n-1;

        while(l <= h){
            int m = l + (h - l)/2;
            if(nums[m] == t){
                return m;
            }else if(nums[m] < t){
                l = m + 1;
            }else{
                h = m - 1;
            }
        }
        return l;
    }
};