class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int mod = 1e9 + 7;
        vector<long long> sub;
        for(int i = 0; i < n; i++){
            long long sum = nums[i];
            for(int j = i+1; j < n; j++){
                sub.push_back(sum % mod);
                sum += nums[j];
            }
            sub.push_back(sum % mod);
        }
        sort(sub.begin(), sub.end());
        long long sum = 0;

        for(int i = left-1; i < right; i++){
            sum = (sum + sub[i]) % mod;
        }
        return (int)sum%mod;
    }
};