class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        int zCnt = 0;
        int len = 0;

        while(j < n){
            if(nums[j] == 0){
                zCnt++;
            }

            while(zCnt > k){
                if(nums[i] == 0){
                    zCnt--;
                }
                i++;
            }
            len = max(len, j - i + 1);
            j++;
        }
        return len;
    }
};