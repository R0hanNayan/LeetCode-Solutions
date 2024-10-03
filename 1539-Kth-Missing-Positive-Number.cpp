class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0, h = n - 1;
        while (l <= h) {
            int m = (l + h) / 2;
            int missing = arr[m] - (m + 1);
            if (missing < k) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        return l + k;
    }
};