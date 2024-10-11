class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<int> chair(n, -1);
        int targetArrivalTime = times[targetFriend][0];
        
        sort(begin(times), end(times));
        
        for(vector<int> &time : times) {
            int arrival = time[0];
            int depart  = time[1];
            for(int i = 0; i<n; i++) {
                if(chair[i] <= arrival) {
                    chair[i] = depart;
                    if(arrival == targetArrivalTime)
                        return i;
                    break;
                }
            }
        }
        return -1;
    }
};