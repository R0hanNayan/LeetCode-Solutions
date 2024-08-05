class Solution {
public:
    void solve(int st, int n, int k, vector<int> temp, vector<vector<int>> &res){
        if(k == 0){
            res.push_back(temp);
            return;
        }

        for(int i = st; i <= n; i++){
            temp.push_back(i);
            solve(i+1, n, k-1, temp, res);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        solve(1, n, k, {}, res);
        return res;
    }
};