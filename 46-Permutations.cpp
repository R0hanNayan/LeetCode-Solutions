class Solution {
public:
    unordered_set<int> st;
    void solve(vector<int>& nums, vector<int> temp, vector<vector<int>> &res){
        if(temp.size() == nums.size()){
            res.push_back(temp);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(st.find(nums[i]) == st.end()){
                temp.push_back(nums[i]);
                st.insert(nums[i]);

                solve(nums, temp, res);

                st.erase(nums[i]);
                temp.pop_back();
            }
        }   
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        solve(nums, {}, res);
        return res;
    }
};