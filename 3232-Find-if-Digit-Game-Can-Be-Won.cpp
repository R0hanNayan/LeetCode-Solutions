class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int tSum = 0;
        int sum = 0;
        int n = nums.size();
        for(auto it : nums){
            tSum += it;
            if(it < 10){
                sum += it;
            }
        }
        int diff = tSum - sum;

        return (diff > sum || sum > diff);
    }
};