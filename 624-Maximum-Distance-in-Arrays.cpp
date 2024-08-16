class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int mini = arr[0].front();
        int maxi = arr[0].back();
        int res = 0;
        int n = arr.size();

        for(int i = 1; i < n; i++){
            int currMin = arr[i].front();
            int currMax = arr[i].back();

            res = max({res, abs(currMin - maxi), abs(mini - currMax)});

            mini = min(mini, currMin);
            maxi = max(maxi, currMax);
        }

        return res;
    }
};