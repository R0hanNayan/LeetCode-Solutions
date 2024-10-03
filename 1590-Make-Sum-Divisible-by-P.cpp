class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int tSum = 0;
        for(auto it : nums) tSum  = (tSum + it) % p;
        int target = tSum % p;

        if(target == 0) return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;
        int curr = 0;
        int res = nums.size();

        for(int j = 0; j < nums.size(); j++){
            curr = (curr + nums[j]) % p;

            int remain = (curr - target + p) % p;
            if(mp.find(remain) != mp.end()){
                res = min(res, j - mp[remain]);
            }
            mp[curr] = j;
        }
        return res == nums.size() ? -1 : res;
    }
};