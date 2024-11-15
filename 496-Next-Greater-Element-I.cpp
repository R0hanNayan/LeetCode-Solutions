class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        unordered_map<int, int> mp;
        stack<int> st;

        for(int i = n2 - 1; i >= 0; i--){
            if(st.empty()){
                mp[nums2[i]] = -1;
            }else{
                while(!st.empty() && nums2[st.top()] <= nums2[i]){
                    st.pop();
                }
                mp[nums2[i]] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }

        vector<int> res;
        for(auto it : nums1){
            if(mp[it] == -1){
                res.push_back(-1);
            }else{
                res.push_back(nums2[mp[it]]);
            }
        }
        return res;
    }
};