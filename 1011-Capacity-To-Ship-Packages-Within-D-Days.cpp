class Solution {
public:
    bool possible(int weight, vector<int>& weights, int days) {
        int currDayCount = 1;
        int currSumWeight = 0;
        for (int& w : weights) {
            currSumWeight += w;

            if (currSumWeight > weight) {
                currDayCount++;
                currSumWeight = w;
            }
        }
        return currDayCount <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while(low < high) {
            int mid = low + (high-low)/2;
            
            if(possible(mid, weights, days))
                high = mid;
            else
                low  = mid+1;
        }
        return low;
    }
};