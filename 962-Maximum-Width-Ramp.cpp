class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n);
        nge[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            nge[i] = max(nums[i], nge[i+1]);
        }
        int i = 0, j = 0;
        int ramp = 0;

        while(j < n){
            while(i < j && nums[i] > nge[j]){
                i++;
            }
            ramp = max(ramp, j - i);
            j++;
        }
        return ramp;
    }
};