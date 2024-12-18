class Solution {
public:
    vector<int> nse(vector<int>& prices){
        int n = prices.size();
        stack<int> st;
        vector<int> ns(n, 0);

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && st.top() > prices[i]){
                st.pop();
            }

            ns[i] = st.empty() ? prices[i] : prices[i] - st.top();
            st.push(prices[i]);
        }
        return ns;
    }
    vector<int> finalPrices(vector<int>& prices) {
        prices = nse(prices);
        return prices;
    }
};