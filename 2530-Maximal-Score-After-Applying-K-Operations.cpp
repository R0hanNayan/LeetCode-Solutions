class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> pq(nums.begin(), nums.end());
        while (k--) {
            int t = pq.top(); 
            pq.pop();
            ans += t; 
            pq.push((t + 2) / 3);
        }
        return ans;
    }
};