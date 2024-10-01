class Solution {
public:
    int getNum(vector<int> &bloomDay, int mid, int k){
        int numOfBouquets = 0;
        int conseCnt = 0;

        for(auto it : bloomDay){
            if(it <= mid){
                conseCnt++;
            }else{
                conseCnt = 0;
            }

            if(conseCnt == k){
                numOfBouquets++;
                conseCnt = 0;
            }
        }

        return numOfBouquets;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l = 0, h = *max_element(begin(bloomDay), end(bloomDay));

        int minDays = -1;

        while(l <= h){
            int mid = l + (h - l)/2;
            if(getNum(bloomDay, mid, k) >= m){
                minDays = mid;
                h = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return minDays;
    }
};