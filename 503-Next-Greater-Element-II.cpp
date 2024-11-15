class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;

        for(int i = 2 * n - 1; i >= 0; i--){
            if(st.empty()){
                res[i % n] = -1;
            }else{
                while(!st.empty() && st.top() <= nums[i % n]){
                    st.pop();
                }
                res[i % n] = st.empty() ? -1 : st.top();
            }
            st.push(nums[i % n]);
        }
        return res;
    }
};