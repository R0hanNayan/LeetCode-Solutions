class Solution {
public:
    vector<int> dp;
    int solve(int i, string &s, unordered_set<string>& st, int &n){
        if(i >= n)  return 0;
        if(dp[i] != -1) return dp[i];
        
        int res = 1 + solve(i + 1, s, st, n);

        for(int j = i; j < n; j++){
            string curr = s.substr(i, j-i+1);
            if(st.count(curr)){
                res = min(res, solve(j+1, s, st, n));
            }
        }
        return dp[i] = res;
    }
    int minExtraChar(string s, vector<string>& dict) {
        unordered_set<string> st(dict.begin(), dict.end());
        int n = s.size();
        dp.resize(n, -1);
        return solve(0, s, st, n);
    }
};