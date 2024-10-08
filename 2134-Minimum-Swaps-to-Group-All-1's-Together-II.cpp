class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int cntOne = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                cntOne++;
            }
        }

        int i = 0, j = 0;
        int currCnt = 0, maxCnt = 0;

        while(j < 2 * n){
            if(nums[j % n] == 1){
                currCnt++;
            }
            if(j-i+1 > cntOne){
                currCnt -= nums[i%n];
                i++;
            }
            maxCnt = max(maxCnt, currCnt);
            j++;
        }
        return cntOne - maxCnt;
    }
};