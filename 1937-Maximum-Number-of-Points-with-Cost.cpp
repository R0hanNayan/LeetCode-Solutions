class Solution {
public:
    typedef long long ll;
    ll maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        vector<ll> prev(n);
        int score = 0;
        
        for(int col = 0; col < n; col++) {
            prev[col] = points[0][col];
        }
        
        for(int i = 1; i<m; i++) {
            vector<ll> curr(n);
            auto left = curr, right = curr;
            //Fill left
            left[0] = prev[0];
            for(int j = 1; j<n; j++) {
                left[j] = max(prev[j], left[j-1]-1); // points[i][j] will be added later            
            }
            
            //Fill right
            right[n-1] = prev[n-1];
            for(int j = n-2; j >= 0; j--) {
                right[j] = max(prev[j], right[j+1]-1); // points[i][j] will be added later
            }
            
            for(int j = 0; j<n; j++)
                curr[j] = points[i][j] + max(left[j], right[j]); // points[i][j] added here
            
            prev = curr;
        }
        return *max_element(prev.begin(), prev.end());
    }
};