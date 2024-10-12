class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(begin(intervals), end(intervals));

        for(auto it : intervals){
            int start = it[0];
            int end = it[1];
            if(!pq.empty() && pq.top() < start){
                pq.pop();
            }
            pq.push(end);
        }
        return pq.size();
    }
};