class Solution {
public:
    int count(vector<int>& nums, int d){
        int n = nums.size();
        int i = 0; int j = 1;
        int cnt = 0;

        while(j < n){
            while((nums[j] - nums[i]) > d){
                i++;
            }
            cnt += j-i;
            j++;
        }
        return cnt;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int l = 0;
        int h = nums[n-1] - nums[0];    //highest distance
        int res = 0;

        while(l <= h){
            int mid = l + (h - l)/2;
            int countPairs = count(nums, mid);

            if(countPairs < k){
                l = mid + 1;
            }else{
                res = mid;
                h = mid - 1;
            }
        }
        return res;
    }
};