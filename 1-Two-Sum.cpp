class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        
        for(int i = 0; i<nums.size(); i++) {
            if(mp.count(k - nums[i]))
                return {mp[k - nums[i]], i};
            mp[nums[i]] = i;
        }
        
        return {};
    }
};