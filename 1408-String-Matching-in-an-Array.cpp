class Solution {
public:
    int sumByD(vector<int>& arr, int d){
        int sum = 0;
        int n = arr.size();
        for(int i = 0; i<n; i++){
            sum += ceil((double)arr[i] / (double)d);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int l = 1, h = INT_MIN;
        for(int i=0; i<n; i++){
            h = max(nums[i], h);
        }
        while(l<=h){
            int m = (l+h)/2;
            if(sumByD(nums, m) <= threshold){
                h = m - 1;
            }else{
                l = m + 1;
            }
        }
        return l;
    }
};