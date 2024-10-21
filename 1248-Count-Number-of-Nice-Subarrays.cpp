class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int>  mp;
        mp[0] = 1;

        int curr = 0;
        int cnt = 0;
        for(auto it : nums){
            curr += (it % 2);
            if(mp.find(curr - k) != mp.end()){
                cnt += mp[curr - k];
            }
            mp[curr]++;
        }
        return cnt;
    }
};