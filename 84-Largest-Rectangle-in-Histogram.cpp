class Solution {
public:
    int largestRectangleArea(vector<int>& ht) {
        int n = ht.size();
        vector<int> nse(n), pse(n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && ht[st.top()] >= ht[i]){
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty())  st.pop();

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && ht[st.top()] >= ht[i]){
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        int maxi = INT_MIN;

        for(int i = 0; i < n; i++){
            maxi = max(maxi, ht[i] * (nse[i] - pse[i] - 1));
        }

        return maxi;
    }
};