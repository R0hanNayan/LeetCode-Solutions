class Solution {
public:
    void solve(vector<int> &arr, int t, vector<vector<int>> &res, vector<int> temp, int ind){
        if(t < 0)   return;
        if(t == 0){
            res.push_back(temp);
            return;
        }

        for(int i=ind; i<arr.size(); i++){
            temp.push_back(arr[i]);
            solve(arr, t-arr[i], res, temp, i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int t) {
        vector<vector<int>> res;
        solve(arr, t, res, {}, 0);
        return res;
    }
};