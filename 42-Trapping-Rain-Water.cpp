class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;
        vector<int> pge(n), nge(n);

        pge[0] = height[0];
        nge[n-1] = height[n-1];

        for(int i = 1; i < n; i++){
            pge[i] = max(height[i], pge[i-1]);
        }

        for(int i = n-2; i >= 0; i--){
            nge[i] = max(height[i], nge[i+1]);
        }

        for(int i = 1; i < n-1; i++){
            water += min(nge[i], pge[i]) - height[i];
        }

        return water;
    }
};