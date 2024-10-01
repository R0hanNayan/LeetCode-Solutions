class Solution {
public:
    bool canEatAll(vector<int>& piles, int mid, int h) {
        int currHour = 0;
        for (auto it : piles) {
            currHour += it / mid;
            if(it % mid != 0)
                currHour++;
        }

        return currHour <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1, r = *max_element(begin(piles), end(piles));
        
        while(l < r) {
            int mid = l + (r-l)/2;
            if(canEatAll(piles, mid, h)) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        return l;
    }
};