class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int largest = 0;
        int res = 0;
        int streak = 0;

        for(auto it : nums){
            if(it > largest){
                largest = it;
                res = 0;
                streak = 0;
            }

            if(it == largest){
                streak++;
            }else{
                streak = 0;
            }

            res = max(res, streak);
        }
        return res;
    }
};
