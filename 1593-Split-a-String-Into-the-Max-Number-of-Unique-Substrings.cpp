class Solution {
public:
    void solve(string &s, int ind, unordered_set<string> &st, int currCnt, int &maxCnt){
        if(currCnt + (s.size() - ind) <= maxCnt)    return;

        if(ind == s.size()) maxCnt = max(maxCnt, currCnt);

        for(int j = ind; j < s.size(); j++){
            string sub = s.substr(ind, j - ind + 1);
            if(st.find(sub) == st.end()){
                st.insert(sub);
                solve(s, j+1, st, currCnt+1, maxCnt);
                st.erase(sub);
            }
        }
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        int maxCnt = 0;
        int currCnt = 0;
        solve(s, 0, st, currCnt, maxCnt);
        return maxCnt;

    }
};